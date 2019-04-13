#pragma once
// win 7
#define _WIN32_WINNT 0x0601

#include <bits/stdc++.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/asio.hpp>
#include <boost/filesystem.hpp>
#include <Windows.h>

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::archive;

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

class Close_Connect {
public:
	bool is_connected = false;
	Close_Connect() {}
	~Close_Connect();
	void connect(string ip);
	void disconnect();
};

int client_run(function<int()>);
void send_file(tcp::socket& s, string filename, string path);
boost::shared_ptr<string> send_cmd(tcp::socket& s, string cmd);
