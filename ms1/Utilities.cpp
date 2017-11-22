#include <sstream>
#include "Utilities.h"


const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) {
	
	std::string token, temp;

		token = str.substr(next_pos, str.find(delimiter));
		if (token == "") throw std::string(str) + std::string ("*** no token found before the delimiter ***");

		next_pos = token.length() + 1;

		temp = str.substr(next_pos);

		temp = temp.substr(next_pos, temp.find(delimiter));

		if (temp != "") {
			more = true;
			field_width++;
		}

	return token;
}

void Utilities::setLogFile(const char* logfile) {
	std::ofstream file(logfile, std::ios::trunc);

}
