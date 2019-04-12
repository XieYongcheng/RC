#include "main.h"
#include "message.h"

io_service service;
tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
tcp::socket sock(service);

int connect() {
	static const int max_times = 10;
	int times = 0;
	while (true) {
		try {
			sock.connect(ep);
			return 0;
		}
		catch (const std::exception&) {
			if (++times > max_times) {
				break;
			}
			cout << "无法连接" << endl;
			Sleep(1000);
		}
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

void send(tcp::socket& s, message m) {
	send(s, m.to_string());
}

void send(tcp::socket& s, int type, string msg) {
	send(s, message(type, msg));
}

void send_file(tcp::socket& s, string filename, string path) {
	send(sock, message::Type::file_name, (path));
	send(sock, message::Type::file, file(filename));
}

boost::shared_ptr<string> get(tcp::socket& s) {
	char temp[4];
	s.read_some(buffer(temp));
	int size = *reinterpret_cast<int*>(&temp);
	boost::shared_ptr<string> str(new string(size, '\0'));
	s.read_some(buffer(*str));
	return str;
}

boost::shared_ptr<string> send_cmd(tcp::socket& s, string cmd) {
	send(s, message::Type::command, cmd);
	message m;
	m.reload(*get(s));

	return boost::shared_ptr<string>(new string(m.msg));
}

void show(string s) {
	MessageBox(NULL, s.c_str(), "", MB_OK);
}

class Close_Connect {
public:
	bool is_connected = false;
	Close_Connect() {
		connect() ? is_connected = false : is_connected = true;
	}
	~Close_Connect() {
		if (is_connected)
			send(sock, message::Type::exit, "");
	}
};

void client_run() {
	Close_Connect close;
	try {
		show(*send_cmd(sock, "echo ni shi **"));
	}
	catch (const std::exception&) {
		cout << "Error" << endl;
	}
}
