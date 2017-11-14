#include<iostream>
#include<fstream>
#include "Message.h"

namespace w5 {

	// -constructor retrieves a record from the in file object, parses the record(as described above) and stores its components in the Message object.c is the character that delimits each record	
	Message::Message(std::ifstream& in, char c) {

		if (!in.fail()) {
			char temp[100];
			in.getline(temp, 200, c);
			
			m_message = temp;
		}
		else *this = Message();
	}

	//copy assignment
	Message& Message::operator=(const Message& msg) {
		if (this != &msg) {
			m_message = msg.m_message;
		}
		return *this;
	}

	//move assignment
	Message&& Message::operator=(Message&& msg) {
		if (this != &msg) {
			m_message = msg.m_message;
		}

		msg.m_message.clear();
		return std::move( *this);
	}

	// -returns true if the object is in a safe empty state
	bool Message::empty() const {
		bool isEmpty = true;
		if (m_message != "") {
			isEmpty = false;
		}
		return isEmpty;
	}
	
	// displays the Message objects within the container
	void Message::display(std::ostream& out) const {
		out << m_message;
	}

	std::ostream& operator<< (std::ostream& os, const Message& s) {
		s.display(os);
		return os;
	}
}