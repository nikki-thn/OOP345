//Demonstration of using smart pointers in a container


#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <numeric>
#include <cassert>
#include <string>
#include <memory>


using namespace std;

struct Egg {
	char* m_color;
	int m_code;

	Egg(const char* color, int code) {
		
		m_color = new char[strlen(color) + 1];
		strcpy(m_color, color);
		m_code = code;
	}

	void display() {
			cout << m_color << endl;
			cout << m_code << endl;	
	}

};

struct Chicken {

	int m_id;
	vector<Egg> vect;
	vector<unique_ptr<Egg>> vect1;

	Chicken(int id) : m_id(id) {}

	void operator+=(const unique_ptr<Egg>& e) {
		vect.push_back(*e);
	}

	void operator-=(unique_ptr<Egg> e) {
		vect1.push_back(std::move(e));
	}



};



int main() {


	//vector<unique_ptr<Egg>> vect1;


	//auto temp = std::make_unique<Egg>("pink", 10);

	//vect1.push_back(std::move(temp));

	//auto temp1 = std::make_unique<Egg>("yellow", 10);

	//vect1.push_back(std::move(temp1));


	//temp.reset();
	//temp1.reset();

	vector<Egg> vect;

	auto temp = std::make_unique<Egg>("white", 10);

	vect.push_back(std::move(*temp));

	std::unique_ptr<Egg> temp1(new Egg("brown", 20));

	vect.push_back(std::move(*temp1));



	Chicken ch(007);

	//passing smart pointer and store in an object vector
	ch += temp;

	//Passing smart pointer and store in a smart pointer vector
	ch -= (std::move(temp1));

	cout << endl;

	return 0;
}
