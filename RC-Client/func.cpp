#include "main.h"
#include "message.h"

io_service service;
tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
tcp::socket sock(service);

void connect() {
	static const int max_times = 10;
	int times = 0;
	while (true) {
		try {
			sock.connect(ep);
			return;
		}
		catch (const std::exception&) {
			if (++times > max_times) {
				break;
			}
			cout << "无法连接" << endl;
		}
	}
	return;
}

void send(tcp::socket& s, string str) {
	int size = static_cast<int>(str.size());
	char* temp = reinterpret_cast<char*>(&size);
	s.write_some(buffer(string() + temp[0] + temp[1] + temp[2] + temp[3] + str));
}

boost::shared_ptr<string> get(tcp::socket& s) {
	char temp[4];
	s.read_some(buffer(temp));
	int size = *reinterpret_cast<int*>(&temp);
	boost::shared_ptr<string> str(new string(size, '\0'));
	s.read_some(buffer(*str));
	return str;
}

void client_run() {
	try {
		send(sock, (message(message::Type::message, "OK").to_string()));
	}
	catch (const std::exception&) {
		cout << "Error" << endl;
	}
}
