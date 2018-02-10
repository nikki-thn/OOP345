/*! *********************************************************
* OOP345 Workshop 2: Copy and Move Semantic
* File: Text.h
* Version: 1.0
* \date Feb 4, 2018
* \author Nikki Truong - 112 314 174
* Description
* This program will implement the copy and move semantics to manage a class with a resource
***********************************************************/


#ifndef W3_TEXT_H
#define W3_TEXT_H
#include <string>

namespace w3 {

	class Text {

		char* m_fileName; // store the fileName of the text file
		size_t m_size; // store the size (number of lines) of the text file
		std::string* m_strings; // a pointer to String which will be used to store the content of the text file

	public:

		Text(); // Default constructor
		Text(const char*); // One parameter constructor
		~Text(); // destructor
		Text(const Text&); // Copy constructor
		Text(Text&&); // Move constructor
		Text& operator= (const Text&); // Copy operator
		Text&& operator= (Text&&); // Move operator

		size_t size() const; // Function return the size of string array
	};
}

#endif
