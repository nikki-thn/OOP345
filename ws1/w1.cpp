/* \file w1.cpp
* \brief This program will take in command line arguments and echo
* to user the first 3 characters of each argument
* \author [Nikki Truong - 112 314 174 - OOP345 - Section C]
* \date [Jan 28, 2018]
*/

#include<iostream>
#include"process.h"

const int w1::MAX = 5;  //!< \var int MAX is maximum number of characters being displayed

int main(int argc, char*argv[]) {

	/*! Check condition, only proceed if number of command line arguments
	* is greater than 1
	*/
	if (argc > 1) {
		std::cout << "Maximum number of characters stored: " << w1::MAX << "\n";

		/* Loop through every argument and call \fn toProcess()
		* to extract the \var MAX characters to print out
		*/
		for (int i = 1; i <= argc - 1; i++) {
			std::cout << (i - 1) << ":";
			toProcess(argv[i]);
		}
	}
	//! If number of argument is equal to one, display error message
	else if (argc == 1) {
		std::cout << "Insufficient number of arguments (min 1)" << std::endl;
		//! \return [exit code 1 when insuffiencient number of arguments]
		return 1;
	}

	//! \return [exit code 0 on sucessful processing]
	return 0;

}
