#pragma once
// Milestone 1 - Utilities Interface
// Utilities.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016
#include <string>
#include <fstream>

class Utilities {

	size_t field_width;           // maximum field width needed 
	static char delimiter;        // field delimiter character
	static std::ofstream logFile; // log file

public:

	//constructor
	Utilities();

	// resets the field width of the current object to fw
	void setFieldWidth(size_t fw);

	//return field_width of the current object
	size_t getFieldWidth() const;

	//set delimiter to the new value
	static void setDelimiter(const char delimiter_);

	/*! \return a modifiable reference to the log file */
	static std::ofstream& Utilities::getLogFile() { return logFile; }

	//return the next token
	const std::string nextToken(const std::string&, size_t&, bool&);

	static void setLogFile(const char*);
};
