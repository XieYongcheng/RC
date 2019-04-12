#include "main.h"


string run(string cmd) {
	string r;
	run(cmd, r);
	return r;
}

// int run(string)
// parameter :
//   cmd: Execute code
//   result: output string
// return :
//   0 = OK
//   1 = error
int run(string cmd, string& result) {
	static const int Line_Size = 256;
	string temp;
	result.swap(temp);
	char buf_ps[Line_Size];
	FILE* out;
	if ((out = _popen(cmd.c_str(), "r")) != NULL) {
		while (fgets(buf_ps, Line_Size, out) != NULL) {
			result += buf_ps;
		}
		_pclose(out);
		out = NULL;
		return 0;
	}
	return 1;
}

