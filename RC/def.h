#pragma once

#include <atlconv.h>
#include <atlbase.h> 
#include <atlstr.h>
#include <comdef.h>
#include <intrin.h>
#include <iphlpapi.h>
#include <Wbemidl.h>
#include <wininet.h>
#include <winsock2.h>

#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "wininet")
#pragma comment (lib, "ws2_32.lib")

using namespace std;

class NetAdapter {
private:
	wstring adapterDesc;
	wstring adapterAddr;
	wstring adapterGW;
	wstring adapterType;
public:
	NetAdapter() {}
	void setAdapterType(wstring);
	void setAdapterDesc(wstring);
	void setAdapterAdr(wstring);
	void setAdapterGW(wstring);
	wstring getAdapterType(void);
	wstring getAdapterDesc(void);
	wstring getAdapterAdr(void);
	wstring getAdapterGW(void);
};

class SystemInfo {
private:
	SystemInfo() {
		this->BIOS = L"BIOS not detected";
		this->OS = L"OS not detected";
		this->RAM = L"RAM not detected";
		this->MB = L"Motherboard not detected";
		this->CPU = L"CPU not detected";
		this->audio = L"Sound card not detected";
		this->uptime = L"Uptime not set";
	}
	wstring BIOS;
	wstring OS;
	wstring CPU;
	wstring MB;
	wstring RAM;
	vector<wstring> GPUDevices;
	vector<wstring> storageMediums;
	vector<wstring> displayDevices;
	vector<wstring> CDROMDevices;
	vector<NetAdapter> networkAdapters;
	vector<wstring> networkAdaptersText;
	wstring audio;
	wstring uptime;
	wstring snapshotGenDateTime;
public:
	static SystemInfo *getCurrentInstance() {
		static SystemInfo *currentInstance = new SystemInfo();
		return currentInstance;
	}
	vector<wstring> getCDROMDevices(void);
	wstring  getBIOS(void);
	wstring  getUptime(void);
	wstring  getCPU(void);
	wstring  getRAM(void);
	wstring  getMB(void);
	wstring  getAudio(void);
	vector<wstring> getGPUDevices(void);
	vector<wstring> getStorageMediums(void);
	vector<wstring> getDisplayDevices(void);
	vector<NetAdapter> getNetworkAdapters(void);
	vector<wstring> getNetworkAdaptersText(void);
	vector<wstring>& getNetworkAdaptersTextRef(void) {
		return this->networkAdaptersText;
	}
	wstring getOS(void);
	wstring getSnapshotGenDateTime();
	void setBIOS(wstring bios);
	void setUptime(wstring uptime);
	void setCPU(wstring CPU);
	void setRAM(wstring RAM);
	void setMB(wstring MB);
	void addDisplayDevice(wstring device);
	void addStorageMedium(wstring medium);
	void addNetworkAdapter(NetAdapter adapter);
	void addNetworkAdapterText(wstring adapter);
	void addGPUDevice(wstring device);
	void setOS(wstring OS);
	void setAudio(wstring audio);
	void addCDROMDevice(wstring CDROM);
	void setSnapshotGenDateTime(wstring dt);
};

typedef struct _RawSMBIOSData {
	BYTE	Used20CallingMethod;
	BYTE	SMBIOSMajorVersion;
	BYTE	SMBIOSMinorVersion;
	BYTE	DmiRevision;
	DWORD	Length;
	PBYTE	SMBIOSTableData;
} RawSMBIOSData, *PRawSMBIOSData;
typedef struct _SMBIOSHEADER_ {
	BYTE Type;
	BYTE Length;
	WORD Handle;
} SMBIOSHEADER, *PSMBIOSHEADER;
typedef struct _TYPE_0_ {
	SMBIOSHEADER	Header;
	UCHAR	Vendor;
	UCHAR	Version;
	UINT16	StartingAddrSeg;
	UCHAR	ReleaseDate;
	UCHAR	ROMSize;
	ULONG64 Characteristics;
	UCHAR	Extension[2]; // spec. 2.3
	UCHAR	MajorRelease;
	UCHAR	MinorRelease;
	UCHAR	ECFirmwareMajor;
	UCHAR	ECFirmwareMinor;
} BIOSInfo, *PBIOSInfo;
#if (NTDDI_VERSION >= NTDDI_VISTA)
typedef  IP_ADAPTER_ADDRESSES_LH IP_ADAPTER_ADDRESSES;
typedef  IP_ADAPTER_ADDRESSES_LH *PIP_ADAPTER_ADDRESSES;
#elif (NTDDI_VERSION >= NTDDI_WINXP)
typedef  IP_ADAPTER_ADDRESSES_XP IP_ADAPTER_ADDRESSES;
typedef  IP_ADAPTER_ADDRESSES_XP *PIP_ADAPTER_ADDRESSES;
#else
//
// For platforms other platforms that are including
// the file but not using the types.
//
typedef  IP_ADAPTER_ADDRESSES_XP IP_ADAPTER_ADDRESSES;
typedef  IP_ADAPTER_ADDRESSES_XP *PIP_ADAPTER_ADDRESSES;
#endif


static wstring RAMFormFactors[24]{
	L"Unknown form factor",
	L"",
	L"SIP",
	L"DIP",
	L"ZIP",
	L"SOJ",
	L"Proprietary",
	L"SIMM",
	L"DIMM",
	L"TSOP",
	L"PGA",
	L"RIMM",
	L"SODIMM",
	L"SRIMM",
	L"SMD",
	L"SSMP",
	L"QFP",
	L"TQFP",
	L"SOIC",
	L"LCC",
	L"PLCC",
	L"BGA",
	L"FPBGA",
	L"LGA"
};
static wstring RAMMemoryTypes[26]{
	L"DDR3",
	L"",
	L"SDRAM",
	L"Cache DRAM",
	L"EDO",
	L"EDRAM",
	L"VRAM",
	L"SRAM",
	L"RAM",
	L"ROM",
	L"Flash",
	L"EEPROM",
	L"FEPROM",
	L"CDRAM",
	L"3DRAM",
	L"SDRAM",
	L"SGRAM",
	L"RDRAM",
	L"DDR",
	L"DDR2",
	L"DDR2 FB-DIMM",
	L"DDR2",
	L"DDR3",
	L"FBD2"
};
static std::wstring storageMediumManufacturers[20]{
	L"Western Digital",
	L"Seagate",
	L"Fujitsu",
	L"Hitachi",
	L"Samsung",
	L"IMB"
};

void trimNullTerminator(std::wstring&);
void trimWhiteSpace(std::wstring&);
std::wstring parseDiskStorageName(std::wstring);
std::wstring convertUIntToString(UINT64);
void DumpSMBIOSStruct(void *, UINT, wchar_t*);
void getNetworkAdapters(SystemInfo*);
int getIpAddress(char *ipBuff);
const char* toPointString(void* p);
const wchar_t* LocateStringW(const char* str, UINT i);
const char* LocateStringA(const char* str, UINT i);
char *getUniCastIP(PIP_ADAPTER_UNICAST_ADDRESS pUnicast);
wstring netAdapterStringWrapper(NetAdapter adapter);
wstring fromChToWideStr(char *value);

int getSystemInformation(SystemInfo *localMachine);
void getBIOS(SystemInfo *localMachine);
void getCPUInfo(void);
void getCPUTemp(SystemInfo *localMachine, HRESULT, IWbemServices*, IWbemLocator*);
void getCPU(SystemInfo *localMachine, HRESULT, IWbemServices*, IWbemLocator*);
void getRAM(SystemInfo *localMachine, HRESULT, IWbemServices*, IWbemLocator*);
void getOS(SystemInfo *localMachine, HRESULT, IWbemServices*, IWbemLocator*);
void getMB(SystemInfo *localMachine, HRESULT, IWbemServices*, IWbemLocator*);
void getGPU(SystemInfo *localMachine, HRESULT, IWbemServices*, IWbemLocator*);
void getMonitor(SystemInfo *localMachine, HRESULT, IWbemServices*, IWbemLocator*);
void getStorage(SystemInfo *localMachine, HRESULT, IWbemServices*, IWbemLocator*);
void getCDROM(SystemInfo *localMachine, HRESULT, IWbemServices*, IWbemLocator*);
void getUptime(SystemInfo *localMachine);
wstring getActualPhysicalMemory(HRESULT, IWbemServices*, IWbemLocator*);
wstring getSocket(HRESULT, IWbemServices*, IWbemLocator*);
void getDimensionsAndFrequency(HRESULT, IWbemServices*, IWbemLocator*, UINT*);
void getAudio(SystemInfo *localMachine, HRESULT, IWbemServices*, IWbemLocator*);
