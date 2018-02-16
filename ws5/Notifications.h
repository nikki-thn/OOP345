#ifndef W5_NOTIFICATIONS_H
#define W5_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

#define ARRAY_SIZE 10

namespace w5 {

	class Notifications {

		Message m_messages[ARRAY_SIZE];

	public:
		Notifications() { } // default constructor - empty
		Notifications(const Notifications&); // -copy constructor
		Notifications& operator=(const Notifications&);// -copy assignment operator
		Notifications(Notifications&&);// -move constructor
		Notifications&& operator=(Notifications&&);// -move assignment operator
		~Notifications();//destructor
		void operator+=(const Message& msg); // -adds msg to the set
		void display(std::ostream& os) const;// -inserts the Message objects to the os output stream

	};
}

#endif