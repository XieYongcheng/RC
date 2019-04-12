#pragma once
// win 7
#define _WIN32_WINNT 0x0601
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <bits/stdc++.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/serialization/string.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/asio.hpp>
#include <Windows.h>

using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::archive;

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

void show(string s);
void server_run();
void client_session(socket_ptr sock);
string run(string cmd);
int run(string cmd, string& result);
