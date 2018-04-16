// Workshop 10 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <thread>
#include "SecureData.h"

namespace w10 {

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

		//// define the promises
		//std::promise<int> promise1;
		//std::promise<int> promise2;

		//// get the futures
		//std::future<int> promiseResult1 = promise1.get_future();
		//std::future<int> promiseResult2 = promise2.get_future();

		//void converter(char* t, char key, int n, const Cryptor& c)
		//converter(text, key, nbytes, Cryptor());

		std::thread t1(converter, text, key, nbytes / 2, Cryptor());
		std::thread t2(converter, text + nbytes / 2, key, nbytes - (nbytes / 2), Cryptor());
		
		//get the result from futures
	//	promiseResult1.get();
	//	promiseResult2.get();

		//join threads
		t1.join();
		t2.join();


	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else {
			// open binary file
			std::fstream f(file, std::ios::out | std::ios::binary | std::ios::trunc);
			if (f.fail()) throw "fail to open file";
			else {

				f.write(text, nbytes);
				f.close();
			}
		}
	}

	void SecureData::restore(const char* file, char key) {
		// open binary file
		std::fstream f(file, std::ios::in | std::ios::binary);
		if (f.fail()) throw "fail to open file" + std::string(file);
		// write binary file here
		else {

			f.seekg(0, std::ios::end);
			nbytes = (int)f.tellg();
			text = new char[nbytes + 1];

			f.seekg(0, std::ios::beg);
			f.read(text, nbytes);
			text[nbytes] = '\0';

			f.close();
		}

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
