#include <iostream>
#include <fstream>
#include <sstream>
#include "Message.h"

namespace w5 {

	/*! default constructor */
	Message::Message() { }

	/*! one parameter constructor take in file stream as an argument
	* When being called, it will stream in the text file into array of strings
	*/
	/*!
	\param takes in ifstream and a character delimiter
	*/
	Message::Message(std::ifstream& in, char c) {

		//if file opens for read in sucessfully
		if (!in.fail()) {

			//read in one line at a time
			std::string temp;
			getline(in, temp, c);

			std::istringstream iss(temp);

			//if the message has a Reply component
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
		else {
			*this = Message();
		}
	}

	/* Copy Operator*/
	void Message::operator= (const Message& rhs) {

		m_message[User] = rhs.m_message[User];
		m_message[Reply] = rhs.m_message[Reply];
		m_message[Tweet] = rhs.m_message[Tweet];
	}

	/*! \return true if message is empty or imcomplete */
	bool Message::empty() const { return m_message[Tweet] == ""; }

	/*! displays the Message object with available components */
	void Message::display(std::ostream& out) const {

		out << "Message" << std::endl;
		out << " User  : " << m_message[User] << std::endl;

		if (m_message[Reply] != "") {
			out << " Reply : " << m_message[Reply] << std::endl;
		}

		out << " Tweet : " << m_message[Tweet] << std::endl;
	}

	/*! Overload for output operator<< */
	std::ostream& operator<< (std::ostream& os, const Message& s) {
		s.display(os);
		return os;
	}
}