/*! *********************************************************
* OOP345 Workshop 2: Copy and Move Semantic
* File: Text.h
* Version: 1.0
* \date Feb 4, 2018
* \author Nikki Truong - 112 314 174
* Description
* This program will implement the copy and move semantics to manage a class with a resource
***********************************************************/


#ifndef W5_NOTIFICATIONS_H
#define W5_NOTIFICATIONS_H

#include <iostream>
/*! *********************************************************
* OOP345 Workshop 4: Containers
* File: Notifications.h
* Version: 1.0
* \date Feb 18, 2018
* \author Nikki Truong - 112 314 174
* Description
* The class manages access to a set of up to 10 Message objects. 
* The Notifications object collects copies of the Message objects,
* owns those copies and destroys them once they are no longer needed.
***********************************************************/

#include "Message.h"

#define MAX_SIZE 10

namespace w5 {

	class Notifications {

		Message *m_messages; //Pointer to array of Messages
		int m_size; //size of the array

	public:

		Notifications(); // default constructor 
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