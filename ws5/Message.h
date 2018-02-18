/*! *********************************************************
* OOP345 Workshop 2: Copy and Move Semantic
* File: Text.h
* Version: 1.0
* \date Feb 4, 2018
* \author Nikki Truong - 112 314 174
* Description
* This program will implement the copy and move semantics to manage a class with a resource
***********************************************************/

#ifndef w5_MESSAGE_H
#define w5_MESSAGE_H
#include <string>

namespace w5 {

	const int COMPONENTS = 3;// max components

	class Message {

		enum Component { User, Tweet, Reply }; //Enum describes 3 components of a message 
		std::string m_message[COMPONENTS];//A message has up to 3 components

	public:

		Message(); //default constructor 
		Message(std::ifstream& in, char c);// Constructor retrieves a record from the in file object, parses the record(as described above) and stores its components in the Message object.c is the character that delimits each record
		void operator= (const Message& rhs); // Copy operator
		bool empty() const;// Returns true if the object is empty
		void display(std::ostream&) const;// Displays the Message objects within the container
	};

	//overload for operator<<
	std::ostream& operator<< (std::ostream& os, const Message& s);
}


#endif
