#include "main.h"
#include "def.h"

void trimNullTerminator(wstring &strToTrim) {
	strToTrim = strToTrim.erase(strToTrim.length());
}
void trimWhiteSpace(wstring &str) {
	if (!str.empty()) {
		int whiteSpaceStart = str.find_last_not_of(L" \t");
		str.erase(whiteSpaceStart + 1);
		int whiteSpaceStartBeginning = str.find_first_not_of(L" \n\t");
		str.erase(str.begin(), str.end() - (str.length() - whiteSpaceStartBeginning));
	}
}
wstring parseDiskStorageName(wstring modelName) {
	wstring finalString = L"";
	if (modelName.find(L"WDC", 0, 3) != wstring::npos) {
		return storageMediumManufacturers[0];
	}
	else if (modelName.find(L"MHS", 0, 3) != wstring::npos) {
		return storageMediumManufacturers[2];
	}
	else if (modelName.find(L"HTS", 0, 3) != wstring::npos) {
		return storageMediumManufacturers[3];
	}
	else if (modelName.find(L"DTL") != wstring::npos) {
		return storageMediumManufacturers[5];
	}
	else if (modelName.find(L"ST", 0, 2) != wstring::npos || modelName.find(L"SC", 0, 2) != wstring::npos) {
		return storageMediumManufacturers[1];
	}
	else {
		return finalString;
	}
}
wstring convertUIntToString(UINT64 num) {
	wstring str;
	wchar_t *buff = new wchar_t[256];
	_swprintf(buff, L"%llu", num);
	str = wstring(buff);
	delete buff;
	return str;
}
void DumpSMBIOSStruct(void *Addr, UINT Len, wchar_t *outData) {
	LPBYTE p = (LPBYTE)(Addr);
	const DWORD lastAddress = ((DWORD)p) + Len;
	PSMBIOSHEADER pHeader;
	pHeader = (PSMBIOSHEADER)p;
	PBIOSInfo pBIOS = (PBIOSInfo)p;
	const char *str = toPointString(p);
	wchar_t *biosVendor = (wchar_t*)LocateStringW(str, pBIOS->Vendor);
	wcscpy(outData, biosVendor);
	wchar_t *biosVersion = (wchar_t*)LocateStringW(str, pBIOS->Version);
	wcscat(outData, L" v.");
	wcscat(outData, biosVersion);
}
void getNetworkAdapters(SystemInfo* localMachine) {
	PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
	PIP_ADAPTER_ADDRESSES pAddresses = NULL;
	DWORD dwRetValAddr = 0;
	//UINT i;
	ULONG outBufLen = 0x3A98;

	pAddresses = (IP_ADAPTER_ADDRESSES *)malloc(outBufLen);
	if (pAddresses == NULL) {
		printf("Memory allocation failed for IP_ADAPTER_ADDRESSES struct\n");
		exit(1);
	}
	dwRetValAddr = GetAdaptersAddresses(AF_INET, GAA_FLAG_INCLUDE_PREFIX, NULL, pAddresses, &outBufLen);
	USES_CONVERSION;
	if (dwRetValAddr == NO_ERROR) {
		pCurrAddresses = pAddresses;
		while (pCurrAddresses) {
			if (pCurrAddresses->IfType != 0x18 && pCurrAddresses->IfIndex != 0x83) {
				PIP_ADAPTER_UNICAST_ADDRESS pUnicast = pCurrAddresses->FirstUnicastAddress;
				NetAdapter adapter = NetAdapter();
				wstring desc = wstring(pCurrAddresses->Description);
				wstring ipAddr = wstring(CA2W(getUniCastIP(pUnicast)));
				wstring type = pCurrAddresses->FriendlyName;
				adapter.setAdapterDesc(desc);
				adapter.setAdapterAdr(ipAddr);
				adapter.setAdapterType(type);
				localMachine->addNetworkAdapterText(netAdapterStringWrapper(adapter));
			}
			pCurrAddresses = pCurrAddresses->Next;
		}
	}
	NetAdapter extIpPlaceHolder = NetAdapter();
	wstring externalIpAddressDesc;
	wstring externalIp = L"Unable to fetch IP";
	wstring type = L"null";
	char buff[128] = { 0 };
	if (getIpAddress(buff)) {
		externalIpAddressDesc = L"Connected to the Internet";
		externalIp = fromChToWideStr(buff);
	}
	else {
		externalIpAddressDesc = L"Not connected to the Internet";
	}
	extIpPlaceHolder.setAdapterDesc(externalIpAddressDesc);
	extIpPlaceHolder.setAdapterAdr(externalIp);
	extIpPlaceHolder.setAdapterType(type);
	//localMachine->addNetworkAdapter(extIpPlaceHolder);
	localMachine->addNetworkAdapterText(netAdapterStringWrapper(extIpPlaceHolder));
}
int getIpAddress(char *ipBuff) {
	int connectionRes = 1;


	HINTERNET hInternet, hFile;
	DWORD rSize;
	char *buffer = new char[128];

	hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

	if ((hFile =
		InternetOpenUrlW(
			hInternet,
			L"https://api.ipify.org",
			NULL,
			0,
			INTERNET_FLAG_RELOAD,
			0)) != NULL) {
		InternetReadFile(hFile, buffer, 128, &rSize);
		buffer[rSize] = '\0';
		strcpy(ipBuff, buffer);
		InternetCloseHandle(hFile);
		connectionRes = 1;
	}
	else {
		connectionRes = 0;
	}
	InternetCloseHandle(hInternet);
	//test fallback

	//strcpy(ipBuff, "1.1.1.1.");
	return connectionRes;
}
const char* toPointString(void* p) {
	return (char*)p + ((PSMBIOSHEADER)p)->Length;
}
const wchar_t* LocateStringW(const char* str, UINT i) {
	static wchar_t buff[2048];
	const char *pStr = LocateStringA(str, i);
	SecureZeroMemory(buff, sizeof(buff));
	MultiByteToWideChar(CP_UTF8, 0, pStr, strlen(pStr), buff, sizeof(buff));
	return buff;
}
const char* LocateStringA(const char* str, UINT i) {
	static const char strNull[] = "Null String";
	if (0 == i || 0 == *str) return strNull;
	while (--i) {
		str += strlen((char*)str) + 1;
	}
	return str;
}
char *getUniCastIP(PIP_ADAPTER_UNICAST_ADDRESS pUnicast) {
	SOCKET_ADDRESS actualAddress = pUnicast->Address;
	LPSOCKADDR sock = actualAddress.lpSockaddr;
	sockaddr_in *act = (sockaddr_in*)sock;
	char *uniCastAddress = inet_ntoa(act->sin_addr);
	return uniCastAddress;
}
wstring netAdapterStringWrapper(NetAdapter adapter) {
	wstring completeString = adapter.getAdapterDesc()
		+ L": " + adapter.getAdapterAdr();
	if (adapter.getAdapterType() != L"null") {
		completeString += L" (" + adapter.getAdapterType() + L")";
	}
	return completeString;
}
wstring fromChToWideStr(char *value) {
	char txtBuff[256] = { 0 };
	wstring wStr;
	wchar_t _wtxtBuff[256] = { 0 };
	strcpy(txtBuff, value);
	mbstowcs(_wtxtBuff, txtBuff, sizeof(txtBuff));
	wStr = wstring(_wtxtBuff);
	return wStr;
}

void NetAdapter::setAdapterDesc(wstring v) {
	(*this).adapterDesc = v;
}
void NetAdapter::setAdapterAdr(wstring v) {
	(*this).adapterAddr = v;
}
void NetAdapter::setAdapterGW(wstring v) {
	//stub
}
wstring NetAdapter::getAdapterDesc(void) {
	return (*this).adapterDesc;
}
wstring NetAdapter::getAdapterAdr(void) {
	return (*this).adapterAddr;
}
wstring NetAdapter::getAdapterGW(void) {
	return L"null";
}
void NetAdapter::setAdapterType(wstring v) {
	(*this).adapterType = v;
}
wstring NetAdapter::getAdapterType(void) {
	return (*this).adapterType;
}