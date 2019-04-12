#include "main.h"
#include "message.h"


message::message(Type type, string msg) :type(type), msg(msg) {

}

void message::reload(string init) {
	stringstream ss;
	ss << init;
	text_iarchive o(ss);
	o >> *this;
}

string message::to_string() {
	stringstream ss;
	text_oarchive o(ss);
	o << msg;
	return ss.str();
}