#include <iostream>
#include"CString.h"

int maxChars;
using namespace std;

namespace w1 {

	CString::CString() {
		m_numOfChars = 0;
		m_string = nullptr;
	}

	CString::CString(const char* cs, int max) {

	//	cout << "Constructor" << endl;
		if (cs != nullptr) {
			m_numOfChars = max;
			maxChars = m_numOfChars;
			m_string = new char[m_numOfChars + 1];
			strncpy(m_string, cs, m_numOfChars);
		}
		else {
			*this = CString();
		}
	}

	CString::~CString() {
	//	cout << "Destructor" << endl;
		delete[] m_string;
	}

	void CString::display(std::ostream& os) const {
		std::cout << m_string << std::endl;
	}

	std::ostream& operator<< (std::ostream& os, const CString& cs) {
		
		cs.display(os);
		return os;
}

}
