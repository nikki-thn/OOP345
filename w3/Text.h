#ifndef W3_TEXT_H
#define W3_TEXT_H

namespace w3 {

	class Text {

		char * m_filename;
		int m_size;
		std::string * m_strings;

	public:

		Text(); //constructor
		Text(const std::string&); // one parameter constructor
		~Text(); //destructor
		Text (const Text& ); //copy constructor
		Text(Text&&); //move constructor
		Text& operator= (const Text& ); //copy operator
		Text&& operator= (const Text&&); //move operator

		size_t size() const;


	};
}

#endif
