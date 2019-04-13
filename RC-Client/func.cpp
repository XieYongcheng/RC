#include "main.h"
#include "message.h"

io_service service;
tcp::socket sock(service);

int connect(tcp::endpoint ep) {
	try {
		sock.connect(ep);
		return 0;
	}
	catch (const std::exception&) {
		//cout << "无法连接" << endl;
	}
	return 1;
}

string file(string filename) {
	fstream fs;
	fs.open(filename, fs.in);
	stringstream ss;
	ss << fs.rdbuf();
	return ss.str();
}

void send(tcp::socket& s, string str) {
	int size = static_cast<int>(str.size());
	char* temp = reinterpret_cast<char*>(&size);
	s.write_some(buffer(string() + temp[0] + temp[1] + temp[2] + temp[3] + str));
}

void send(tcp::socket & s, message m) {
	send(s, m.to_string());
}

void send(tcp::socket & s, int type, string msg) {
	send(s, message(type, msg));
}

void send_file(tcp::socket & s, string filename, string path) {
	send(s, message::Type::file_name, (path));
	send(s, message::Type::file, file(filename));
}

boost::shared_ptr<string> get(tcp::socket & s) {
	char temp[4];
	s.read_some(buffer(temp));
	int size = *reinterpret_cast<int*>(&temp);
	boost::shared_ptr<string> str(new string(size, '\0'));
	s.read_some(buffer(*str));
	return str;
}

boost::shared_ptr<string> send_cmd(tcp::socket & s, string cmd) {
	send(s, message::Type::command, cmd);
	message m;
	m.reload(*get(s));

	return boost::shared_ptr<string>(new string(m.msg));
}

void show(string s) {
	MessageBoxA(NULL, s.c_str(), "", MB_OK);
}

int client_run(function<int()> func) {
	try {
		return func();
	}
	catch (const std::exception&) {
		cout << "Error" << endl;
	}
	return 0;
}

Close_Connect::~Close_Connect() {
	if (is_connected) {
		send(sock, message::Type::exit, "");
		sock.close();
		sock = tcp::socket(::service);
		is_connected = false;
	}
}

void Close_Connect::connect(string ip) {
	tcp::endpoint ep(ip::address::from_string(ip), 2001);
	::connect(ep) ? is_connected = false : is_connected = true;
}

void Close_Connect::disconnect() {
	if (is_connected) {
		send(sock, message::Type::exit, "");
		sock.close();
		sock = tcp::socket(::service);
		is_connected = false;
	}
}
