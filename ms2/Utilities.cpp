/*! *********************************************************
* OOP345 Milestone 1: Tasks
* File: Utilities.cpp
* \date March 15, 2018
* \author Nikki Truong - 112 314 174
***********************************************************/

#include <sstream>
#include "Utilities.h"

char Utilities::delimiter = '\n';
const int max_width = 13;


/*! Default constructor */
Utilities::Utilities() : field_width(1) {}

/*! \param string: record
* \param size_t: staring position to read
* \param boolean: if there are more token
* function will extract a component from a string and return the extracted token
*/
const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) {

	//placeholder variables for extraction
	std::string token, temp;

	//begin reading
	if (next_pos < str.length()) { //if next character to read is not the last

		temp = str.substr(next_pos);

		std::istringstream iss(temp);

		getline(iss, token, delimiter);

		next_pos += token.length() + 1;
	}
	else more = false;

	//Trim white space from token
	size_t first = token.find_first_not_of(' ');
	token.erase(0, first);
	size_t last = token.find_last_not_of(' ');
	token.erase(last + 1);

	//update if its current value is less than the size of the token extracted.  
	if (field_width < token.length() && token.length() < max_width) field_width = token.length();

	return token;
}

/*! resets the field width of the current object to fw */
void Utilities::setFieldWidth(size_t fw) { field_width = fw; }

/*! \return field_width of the current object */
size_t Utilities::getFieldWidth() const { return field_width; }

/*! set delimiter to the new value */
void Utilities::setDelimiter(const char delimiter_) { Utilities::delimiter = delimiter_; }

/*! \return a modifiable reference to the log file */
//std::ofstream& Utilities::getLogFile() { return logFile; }

/*! Function received address of a log file and opens this file for writting and trucation */
void Utilities::setLogFile(const char* logfile) {

	std::ofstream file(logfile, std::ios::trunc);
}
