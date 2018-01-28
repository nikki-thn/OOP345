/* \file CString.h
* \brief header file for \class CString class, this file contains
* the prototypes of CString data members and member functions
* \author [Nikki Truong - 112 314 174 - OOP345 - Section C]
* \date [Jan 28, 2018]
*/


#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include<iostream>

namespace w1 {

	const int MAX = 3; //!< \var int MAX is maximum number of characters being displayed
	
	class CString {

		char* m_string; //!< \brief private member to store the processed string

	public:

		/*! \fn Default Constructor
		 * Takes in zero parameter and initlize m_string to null
		*/
		CString();

	    /*! \fn One parameter constructor
		 * \param[in] [string] [a C-type string that is passed to be exact]
		*/
		CString(const char* string); 

		/*! \fn Destructor
		* \brief Clean up memory
		*/
		~CString();

		/*! \fn display
		* \para[in] [os] [takes in a reference of ostream to display the string
		* to output stream]
		*/
		void display(std::ostream& os) const;
	};

	/*! \fn overload of operator<< for \class CString 
	* \para[in] [os] [takes in a reference of ostream to display the string
	* to output stream]
	*/
	std::ostream& operator<< (std::ostream& os, const CString& aString);
};

#endif
