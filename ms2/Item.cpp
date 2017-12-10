#include <vector>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"
#include "stdlib.h"

size_t Item::field_width = 0;
const size_t numToken = 5;

Item::Item(const std::string& record_) {
	
	name = "";
	filler = "";
	remover = "";
	code = 1;
	description = "no detailed description";

	Utilities exactToken;
	std::string temp;
	size_t pos = 0;
	bool more = true;
	std::vector<std::string> tokens(numToken); //stores all available tokens

	for (size_t i = 0; i < numToken && more; i++) {
		temp = exactToken.nextToken(record_, pos, more);
		if (temp != "") tokens[i] = temp;
	}

	for (auto& i : tokens) {
		size_t first = i.find_first_not_of(' ');
		i.erase(0, first);
		size_t last = i.find_last_not_of(' ');
		i.erase(last + 1);
	}

	if (tokens[0] != "") {
		name = tokens[0];
	}
	else throw std::string(record_) + std::string("*** no name has been specified ***");

	//update the current object's field_width if its current
	// value is less than the size of the token extracted.
	if (field_width < exactToken.getFieldWidth()) {
		field_width = exactToken.getFieldWidth();
	}

	if (tokens[1] != "") filler = tokens[1];
	if (tokens[2] != "") remover = tokens[2];
	if (tokens[3] != "") code = atoi(tokens[3].c_str());
	if (tokens[4] != "") description = tokens[4];
}


void Item::display(std::ostream& os , bool full) const {

	os << std::left << std::setw(field_width + 3) << name << std::endl;
	os << std::right << std::setw (field_width + 3) << " [00" << code <<  " ] ";

	if (full == true) {
		os << "From " << std::left << std::setw(field_width) << filler;
		os << "To " << std::left << std::setw(field_width) << remover << std::endl;
		os << std::left << std::setw(field_width) << ": " << description << std::endl;
	}
}