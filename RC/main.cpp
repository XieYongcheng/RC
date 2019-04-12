#include "main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nShowCmd) {
	MessageBox(NULL, (run("echo oo") + "\n" + run("echo nn")).c_str(), "", MB_OK);

	return 0;
}
