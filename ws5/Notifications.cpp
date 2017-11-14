#include <iostream> 
#include "Notifications.h"

namespace w5 {

	//- copy constructor
	Notifications::Notifications(const Notifications& rhs) {
		*this = rhs;
	}

	//-copy assignment operator
	Notifications& Notifications::operator=(const Notifications& rhs) {

		if (this != &rhs) {

			for (int i = 0; i < ARRAY_SIZE; i++) {
				m_messages[i] = rhs.m_messages[i];
			}
		}
		return *this;
	}

	//- move constructor
	Notifications::Notifications(Notifications&& rhs) {

		for (int i = 0; i < ARRAY_SIZE; i++) {
			m_messages[i] = rhs.m_messages[i];
		}

	}

	// -move assignment operator
	Notifications&& Notifications::operator=(Notifications&& rhs) {
		if (this != &rhs) {

			for (int i = 0; i < ARRAY_SIZE; i++) {
				m_messages[i] = rhs.m_messages[i];
			}

			delete[] rhs.m_messages;
		}
		return std::move(*this);
	}

	//- destructor
	Notifications::~Notifications() {
	}

	//- adds msg to the set
	void Notifications::operator+=(const Message& msg) {
		int index = -1;
		for (int i = 0; i < ARRAY_SIZE; i++) {
			if(m_messages[i].empty()) {
				index = i;
				break;
			}
		}
		if (index >= 0 && index < ARRAY_SIZE) {
			m_messages[index] = msg;
		}
	}

	// - inserts the Message objects to the os output stream
	void Notifications::display(std::ostream& os) const {

		for (int i = 0; i < ARRAY_SIZE; i++) {

			if (!m_messages[i].empty()) {
				os << m_messages[i] << std::endl;
			}
		}
	}
}