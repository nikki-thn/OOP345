/* \file process.cpp
* \brief this file contains the implementation of \fn toProcess()
* \author [Nikki Truong - 112 314 174 - OOP345 - Section C]
* \date [Jan 28, 2018]
*/

#include<iostream>
#include"process.h"
#include "CString.h"

/*! \fn toProcess()
 * [This funtion will take in a C-type string, use CString class to exact
 * and print out the string that is stored by CString]
 * \param[in] [string] [a C-type string to be processed]
 */
void toProcess(const char* string) {

	w1::CString aString(string);
	std::cout << aString;
}
