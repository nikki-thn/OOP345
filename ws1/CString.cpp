/*!
* \class [CString]
* \brief [class CString takes in a string, exact and store \var MAX characters]
* [class CString will take in a string, exact and only store the \var MAX characters
* as its data member]
* \author [Nikki Truong - 112 314 174 - OOP345 - Section C]
* \date [Jan 28, 2018]
*/

#include <iostream>
#include"CString.h"

namespace w1 {

	//! \fn Default Constructor
	CString::CString() {
		m_string = nullptr;
	}

	//! \fn One Parameter Constructor
	CString::CString(const char* cs) {

		if (cs != nullptr) {
			m_string = new char[MAX + 1];
			strncpy(m_string, cs, MAX);
			m_string[MAX] = '\0';
		}
		else {
			*this = CString();
		}
	}

	//! \fn Destructor
	CString::~CString() {
		delete[] m_string;
	}

	//! \fn display()
	void CString::display(std::ostream& os) const {
		std::cout << m_string << std::endl;
	}

	//! \fn helper overload operator<<
	std::ostream& operator<< (std::ostream& os, const CString& cs) {
		cs.display(os);
		return os;
	}

}
