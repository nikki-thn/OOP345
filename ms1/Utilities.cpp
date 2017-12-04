#include <sstream>
#include "Utilities.h"

char Utilities::delimiter = '\n';

const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) {

	std::string token, temp;

	if (next_pos < str.length()) {

		temp = str.substr(next_pos);

		std::istringstream iss(temp);

		getline(iss, token, delimiter);

		next_pos += token.length() + 1;
	}
	else more = false;

	//update if its current value is less than the size of the token extracted.  
	if(field_width < token.length() && token.length() < 13) field_width = token.length();

	return token;
}



void Utilities::setLogFile(const char* logfile) {
	std::ofstream file(logfile, std::ios::trunc);

}