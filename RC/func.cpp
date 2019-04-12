#include "main.h"
#include "message.h"

io_service service;
tcp::endpoint ep(tcp::v4(), 2001);
tcp::acceptor acc(service, ep);

void send(tcp::socket& s, string str) {
	int size = static_cast<int>(str.size());
	char* temp = reinterpret_cast<char*>(&size);
	s.write_some(buffer(string() + temp[0] + temp[1] + temp[2] + temp[3] + str));
}

boost::shared_ptr<string> get(tcp::socket & s) {
	char temp[4];
	s.read_some(buffer(temp));
	int size = *reinterpret_cast<int*>(&temp);
	boost::shared_ptr<string> str(new string(size, '\0'));
	s.read_some(buffer(*str));
	return str;
}


void show(string s) {
	MessageBox(NULL, s.c_str(), "", MB_OK);
}

void server_run() {
	while (true) {
		socket_ptr sock(new tcp::socket(service));
		acc.accept(*sock);
		thread(bind(client_session, sock)).detach();
	}
}

void client_session(socket_ptr sock) {
	try {
		message m;
		m.reload(*get(*sock));
		if (m.type == message::Type::message)
			show(m.msg);
		while (true) {
			break;
		}
	}
	catch (const std::exception&) {
		// when user disconnection
		// TODO:
	}
}

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
int run(string cmd, string & result) {
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

