// Workshop 10 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <thread>
#include "SecureData.h"

namespace w10 {

	//void converter(std::promise<int> i, char* t, char key, int n, const Crystor& c){
	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key) {
		// open text file
		std::fstream input(file, std::ios::in);
		if (!input)
			throw std::string("\n***Failed to open file ") +
			std::string(file) + std::string(" ***\n");

		// copy from file into memory
		nbytes = 0;
		input >> std::noskipws;
		while (input.good()) {
			char c;
			input >> c;
			nbytes++;
		}
		nbytes--;
		input.clear();
		input.seekg(0, std::ios::beg);
		text = new char[nbytes + 1];

		int i = 0;
		while (input.good())
			input >> text[i++];
		text[--i] = '\0';

		std::cout << "\n" << nbytes << " bytes copied from text "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		std::cout << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key) {
		//converter(text, key, nbytes, Cryptor());

		//// define the promises
		//std::promise<int> promise1;
		//std::promise<int> promise2;

		//// get the futures
		//std::future<int> promiseResult1 = promise1.get_future();
		//std::future<int> promiseResult2 = promise2.get_future();

		//void converter(char* t, char key, int n, const Cryptor& c)
		//converter(text, key, nbytes, Cryptor());
		
		std::thread t1(std::bind(converter, text, key, nbytes, Cryptor()));
		std::thread t2(std::bind(converter, text, key, nbytes, Cryptor()));

		//get the result from futures
		//	promiseResult1.get();
		//	promiseResult2.get();

		//join threads
		t1.join();
		t2.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {

		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");

		else {

			//TODO:
			// open binary file
			std::fstream fs(file, std::ios::out | std::ios::binary);
			if (fs.fail()) throw "fail to open file";
			else {

				// write binary file here
				fs.write(text, nbytes);
				fs.close();
			}
		}
	}

	void SecureData::restore(const char* file, char key) {

		//TODO:
		// open binary file
		std::fstream fs(file, std::ios::in | std::ios::binary);
		//if (fs.fail()) throw "fail to open file" + std::string(file);

		// write binary file here
		fs.seekg(0, std::ios::end); //go to the beginning of the file
		nbytes = static_cast<int>(fs.tellg()); //go to the last position of the file aka the size
		text = new char[nbytes + 1]; //allocate memory

		fs.seekg(0, std::ios::beg); //rewind to the beginning again and start reading
		fs.read(text, nbytes); //read in each character
		text[nbytes] = '\0'; //put the null character to end the c-style string

		fs.close(); //close file

		/*
		nbytes = 0;
		input >> std::noskipws;
		while (input.good()) {
			char c;
			input >> c;
			nbytes++;
		}
		nbytes--;
		input.clear();
		input.seekg(0, std::ios::beg);
		text = new char[nbytes + 1];

		int i = 0;
		while (input.good())
			input >> text[i++];
		text[--i] = '\0';
		*/



		std::cout << "\n" << nbytes + 1 << " bytes copied from binary file "
			<< file << " into memory (null byte included)\n";
		encoded = true;

		// decode using key
		code(key);
		std::cout << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}

}


//http://www.uni-obuda.hu/users/mohosp/2008_9_2/C_Jegyzetek/Header_filek/iostream/istream/tellg.html
