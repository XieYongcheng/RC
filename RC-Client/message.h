#pragma once

class message {
private:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& type;
		ar& msg;
	}

public:
	class Type {
	public:
		static const int message = 1;
		static const int command = 2;
		static const int null = 3;
		static const int result = 4;
		static const int file = 5;
		static const int file_name = 6;
		static const int exit = 7;
	};
	message(int type = Type::null, string msg = "");

public:
	string to_string();
	void reload(string init);

public:
	int type;
	string msg;
};

