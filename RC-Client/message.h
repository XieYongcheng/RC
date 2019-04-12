#pragma once

class message {
public:
	enum class Type {
		message_, command, null,
	};
	message(Type type = Type::null, string msg = "");

	template<class Archive>
	void save(Archive& ar, const unsigned int version) {
		ar& type;
		ar& msg;
	}

	template<class Archive>
	void load(Archive& ar, const unsigned int version) {
		ar& type;
		ar& msg;
	}

	BOOST_SERIALIZATION_SPLIT_MEMBER()
public:
	string to_string();
	void reload(string init);

public:
	friend class boost::serialization::access;
	string msg;
	Type type;
};

