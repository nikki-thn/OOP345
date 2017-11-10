#include <iostream>
#include <string>
#include"Text.h"

using namespace std;

namespace w3 {

	Text::Text() { //constructor
	}
	Text::Text(const string&){ // one parameter constructor
	}
	Text::~Text(){ //destructor
	}
	Text::Text(const Text&){ //copy constructor
	}
	Text::Text(Text&&){ //move constructor
	}
	Text& Text::operator= (const Text&){ //copy operator
	}
	Text&& Text::operator= (const Text&&){ //move operator
	}
	size_t Text::size() const {
	}
}