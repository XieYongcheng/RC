#include "main.h"
#include "message.h"


message::message(int type, string msg) :type(type), msg(msg) {
}

void message::reload(string init) {
	stringstream ss;
	ss << init;
	text_iarchive i(ss);
	i >> *this;
}

string message::to_string() {
	stringstream ss;
	text_oarchive o(ss);
	o << *this;
	return ss.str();
}