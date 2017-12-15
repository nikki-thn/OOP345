#include <sstream>
#include "Utilities.h"

char Utilities::delimiter = '\n';
const int max_width = 13;


const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) {

	std::string token, temp;

	if (next_pos < str.length()) {

		temp = str.substr(next_pos);

		std::istringstream iss(temp);

		getline(iss, token, delimiter);

		next_pos += token.length() + 1;
	}
	else more = false;


	size_t first = token.find_first_not_of(' ');
	token.erase(0, first);
	size_t last = token.find_last_not_of(' ');
	token.erase(last + 1);
	
	//update if its current value is less than the size of the token extracted.  
	if(field_width < token.length() && token.length() < max_width) field_width = token.length();

	return token;
}



void Utilities::setLogFile(const char* logfile) {
	std::ofstream file(logfile, std::ios::trunc);

}
