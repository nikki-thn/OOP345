/* \file Textg.h
* \brief header file for \class Text class which process a text file , store and display it
* \author [Nikki Truong - 112 314 174 - OOP345 - Section C]
* \date [Jan 28, 2018]
*/

#ifndef W3_TEXT_H
#define W3_TEXT_H
#include <string>

namespace w3 {

	class Text {

		char* m_fileName; //!< \brief store the fileName of the text file
		size_t m_size; //!< \brief store the size (number of lines) of the text file
		std::string* m_strings; //!< a pointer to String which will be used to store the content of the text file

	public:

		Text(); //constructor
		Text(const char*); // one parameter constructor
		~Text(); //destructor
		Text(const Text&); //copy constructor
		Text(Text&&); //move constructor
		Text& operator= (const Text&); //copy operator
		Text&& operator= (Text&&); //move operator

		size_t size() const { return m_size; }

		void display() const;
	};
}

#endif
