#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include<iostream>

namespace w1 {

	class CString {

		int m_numOfChars;
		char* m_string;

	public:

		CString();
		CString(const char*, int);
		~CString();
		void display(std::ostream&) const;
		//std::istream read(std::istream&);

	};

	std::ostream& operator<< (std::ostream& os, const CString&);
	//std::istream& operator>> (std::istream is, CString&);
};

#endif
