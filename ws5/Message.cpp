#include <iostream>
#include <fstream>
#include <sstream>
#include "Message.h"

namespace w5 {

	// -constructor retrieves a record from the in file object, parses the record(as described above) and stores its components in the Message object.c is the character that delimits each record	
	Message::Message(std::ifstream& in, char c) {

		if (!in.fail()) {

			std::string temp;
			getline(in, temp, c);

			std::istringstream iss(temp);

			if (temp.find_first_of('@') < temp.length()) {
				getline(iss, m_message[User], '@');
				getline(iss, m_message[Reply], ' ');
				getline(iss, m_message[Tweet]);
			}
			else {
				getline(iss, m_message[User], ' ');
				getline(iss, m_message[Tweet]);
				m_message[Reply] = "";
			}	
		}
		else *this = Message();
	}

	// -returns true if the object is in a safe empty state
	bool Message::empty() const { return m_message[Tweet] == ""; 
	}

	// displays the Message objects within the container
	void Message::display(std::ostream& out) const {

		out << "Message" << std::endl;
		out << " User  : " << m_message[User] << std::endl;

		if (m_message[Reply] != "") {
			out << " Reply : " << m_message[Reply] << std::endl;
		}

		out << " Tweet : " << m_message[Tweet] << std::endl;
	}

	std::ostream& operator<< (std::ostream& os, const Message& s) {
		s.display(os);
		return os;
	}
}