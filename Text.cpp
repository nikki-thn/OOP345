/*! \file Text.cpp
* This program will implement the copy and move semantics to manage a class with a resource
* \author [Nikki Truong - 112 314 174 - OOP345 - Section C]
* \date [Feb 02, 2018]
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "Text.h"

using namespace std;

namespace w3 {

	/*! Default constructor set memebers to safe-empty state */
	Text::Text() : m_fileName(nullptr), m_size(0), m_strings(nullptr) { }

	/*! one parameter constructor take in file name as an argument
	* When being called, it will stream in the text file into array of strings
	*/
	/*!
	\param C-style string storing the name of the text file
	*/
	Text::Text(const char* filename) {

		m_fileName = new char[strlen(filename) + 1];
		strcpy(m_fileName, filename);

		fstream file;
		file.open(m_fileName, ios::in);

		if (file.is_open() && !file.fail()) {

			char temp[200];
			int size = 0;

			// count the lines to allocate memory
			while (!file.eof()) {
				file.getline(temp, 100, '\n');
				size++;
			}

			// reset position to read in from the beginning
			file.seekg(0);

			// Copy the size to m_size member
			m_size = size;

			// allocate dynamic memory for the text
			m_strings = new string[m_size];

			// Copy each line of text into a string 
			for (int i = 0; i < m_size; i++) {
				file.getline(temp, 100, '\n');
				m_strings[i] = temp;
			}

			// close file after finish reading
			file.close();
		}
		else {

			// If file reading fails, set members to safe-empty state
			*this = Text();
		}
	}

	/*! Destructor */
	Text::~Text() {

		//clean up resources
		delete[] m_fileName;
		delete[] m_strings;
	}

	/*! Copy constructor */
	Text::Text(const Text& rhs) {
		m_strings = nullptr;
		m_fileName = nullptr;
		*this = rhs; // Calling copy assignment to do the copying
	}

	/*! Move constructor */
	Text::Text(Text&& rhs) {

		// Copy filename
		m_fileName = rhs.m_fileName;

		// Copy size
		m_size = rhs.m_size;

		//Copy the string array
		m_strings = rhs.m_strings;

		// clean up resources
		rhs.m_fileName = nullptr;
		rhs.m_size = 0;
		rhs.m_strings = nullptr;
	}

	/*! Copy operator */
	Text& Text::operator= (const Text& rhs) {

		if (this != &rhs) { // Check for self-assignment

			// copy non-resource member
			m_size = rhs.m_size;

			if (rhs.m_strings != nullptr && rhs.m_fileName != nullptr) {

				// Dealloacte old memory and allocate new resource for copy
				delete[] m_fileName;
				m_fileName = new char[strlen(rhs.m_fileName) + 1];
				strcpy(m_fileName, rhs.m_fileName);

				// Dealloacte old memory and allocate new resource for copy
				delete[] m_strings;
				m_strings = new string[m_size];
				for (int i = 0; i < m_size; i++) {
					m_strings[i] = rhs.m_strings[i];
				}
			}
		}

		return *this;
	}

	/*! Move operator */
	Text&& Text::operator= (Text&& rhs) {

		if (&rhs != this) { // Check for self-assignment

			// Transfer over from one object to another, copy pinter is fine
			m_fileName = rhs.m_fileName;
			m_size = rhs.m_size;
			m_strings = rhs.m_strings;
			
			//Clean up 
			rhs.m_fileName = nullptr;
			rhs.m_size = 0;
			rhs.m_strings = nullptr;
		}

		return std::move(*this);
	}

	//! Function return the size of string array 
	/*!
	  \return interger storing size of the string array
	*/
	size_t Text::size() const { return m_size; }

}