#ifndef W3_TEXT_H
#define W3_TEXT_H
#include <string>

namespace w3 {

	class Text {

		char* m_fileName;
		size_t m_size;
		std::string* m_strings;

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
