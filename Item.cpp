#include <vector>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"
#include "stdlib.h"

size_t Item::field_width = 0;
const size_t numToken = 5;

Item::Item(const std::string& record_) {

	code = 1;
	description = "no detailed description";

	Utilities exactToken;
	std::string temp;
	size_t pos = 0;
	bool more = true;
	std::vector<std::string> tokens(numToken); //stores all available tokens

	for (size_t i = 0; i < numToken && more; i++) {
		temp = exactToken.nextToken(record_, pos, more);
		if (field_width < temp.length()) field_width = temp.length();
		if (!temp.empty()) tokens[i] = temp;

	}

	if (!tokens[0].empty()) name = tokens[0];
	else throw std::string(record_ + "<-- *** no token found before the delimiter ***");

	if (!tokens[1].empty()) filler = tokens[1];
	if (!tokens[2].empty()) remover = tokens[2];
	if (!tokens[3].empty()) code = atoi(tokens[3].c_str());
	if (!tokens[4].empty()) description = tokens[4];


	//if (field_width < tokens[4].length()) field_width = tokens[4].length();

}

Item& Item::operator++(int value) {
	code += value;
	return *this;
}


void Item::display(std::ostream& os, bool full) const {

	//*** Width length wrong, ask!!!

	os << std::setfill(' ');
	os << std::left << std::setw(field_width) << name;

	os << std::right << " [" << std::setw(CODE_WIDTH) << std::setfill('0') << code << "] ";

	if (full == true) {
		os << "From " << std::setw(field_width) << std::left << std::setfill(' ') << filler << " To " << remover << std::endl;
		os << std::right << std::setw(field_width + CODE_WIDTH + 4) << " : " << description << std::endl;
	}
}