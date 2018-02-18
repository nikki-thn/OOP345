#include <iostream> 
#include "Notifications.h"

namespace w5 {

	/*! default constructor */
	Notifications::Notifications() : m_messages(nullptr), m_size(0) {};

	/*! copy constructor */
	Notifications::Notifications(const Notifications& rhs) {
		if (this != &rhs) {
			m_messages = nullptr;
			*this = rhs;
		}
	}

	/*! copy assignment operator */
	Notifications& Notifications::operator=(const Notifications& rhs) {

		//Check for self-assignment
		if (this != &rhs) {

			m_size = rhs.m_size;

			delete[] m_messages;
			m_messages = new Message[m_size];

			for (int i = 0; i < m_size; i++) {
				m_messages[i] = rhs.m_messages[i];
			}
		}
		return *this;
	}

	/*! move constructor */
	Notifications::Notifications(Notifications&& rhs) {

		m_size = rhs.m_size;
		m_messages = rhs.m_messages;

		rhs.m_size = 0;
		rhs.m_messages = nullptr;
	}

	/*! move assignment operator */
	Notifications&& Notifications::operator=(Notifications&& rhs) {

		//transfer ownership of resources
		m_messages = rhs.m_messages;
		m_size = rhs.m_size;

		//clean up resources
		rhs.m_size = 0;
		rhs.m_messages = nullptr;

		return std::move(*this);
	}

	/*! destructor */
	Notifications::~Notifications() {
		delete[] m_messages;
	}

	/*! adds msg to the set */
	void Notifications::operator+=(const Message& msg) {

		Notifications temp = *this;
		if (m_size < MAX_SIZE) {

			delete[] m_messages;
			m_size = temp.m_size;
			m_messages = new Message[m_size + 1];
			
			for (int i = 0; i < m_size; i++) {
				m_messages[i] = temp.m_messages[i];
			}
			
			m_messages[m_size] = msg;	
			m_size++;
		}
	}

	/*! inserts the Message objects to the os output stream */
	void Notifications::display(std::ostream& os) const {

		for (int i = 0; i < m_size; i++) {

			if (!m_messages[i].empty()) {
				os << m_messages[i] << std::endl;
			}
		}
	}

}