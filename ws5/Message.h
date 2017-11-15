#ifndef w5_MESSAGE_H
#define w5_MESSAGE_H
#include <string>

namespace w5 {

	class Message {

		std::string m_message;

	public:
		Message() : m_message("") { } //default constructor
		Message(std::ifstream& in, char c);// -constructor retrieves a record from the in file object, parses the record(as described above) and stores its components in the Message object.c is the character that delimits each record
		Message& operator=(const Message&); //copy assignment
		Message&& operator=(Message&&); //move assignment
		bool empty() const;// -returns true if the object is in a safe empty state
		void display(std::ostream&) const;// -displays the Message objects within the container
		
	};

	std::ostream& operator<< (std::ostream& os, const Message& s);
}
#endif