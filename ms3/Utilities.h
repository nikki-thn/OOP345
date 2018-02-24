#pragma once
// Milestone 1 - Utilities Interface
// Utilities.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016
#include <string>
#include <fstream>

//extern const unsigned int max_width;

class Utilities {

	size_t field_width;           // maximum field width needed 
	static char delimiter;        // field delimiter character
	static std::ofstream logFile; // log file

public:

	//constructor
	Utilities() : field_width(1) {}

	// resets the field width of the current object to fw
	void setFieldWidth(size_t fw) { field_width = fw; }

	//return field_width of the current object
	size_t getFieldWidth() const { return field_width;  }

	//set delimiter to the new value
	static void setDelimiter(const char delimiter_) { Utilities::delimiter = delimiter_; }

	//return logFile static member
	static std::ofstream& getLogFile() { return logFile;  }

	const std::string nextToken(const std::string&, size_t&, bool&);

	static void setLogFile(const char*);
};
