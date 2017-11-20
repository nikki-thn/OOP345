#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <numeric>
#include <cassert>
#include <memory>


using namespace std;

struct Hen {
	unsigned m_id;
	float m_numEggs;

	Hen(unsigned id, float numEggs) : m_id(id), m_numEggs(numEggs) {}
	~Hen() {}
};

auto GetHen(unsigned id, float numEggs) -> unique_ptr<Hen> {
	return make_unique<Hen>(id, numEggs);
}


int main() {

	//******UNIQUE_PTR

	//declare a smart pointer
	//this is similar to int* intPtr = nullptr;
	auto smrtPtr1 = unique_ptr<int>{ nullptr };

	//this is letting the pointer points to the integer 123
	auto smrtPtr2 = unique_ptr<int>{ new int(123) };

	//**best practice
	auto smrtPtr3 = make_unique<int>(123);

	//create a pointer to an object using smart pointer
	auto hen = make_unique<Hen>(1, 5.6f);

	//auto hen2 = hen *** prohibitted
	auto hen2 = move(hen);

	//However, we can make a copy of the object to another object (not pointer to pointer
	//Hence, preventing two pointer to share same resources
//	Hen newCopy = *hen; //dereferenced ptr so we making a new object

	Hen& ref = *hen; //making reference instead of copying

	//this will copy the pointer to another pointer while releasing the object????
	Hen *ptr = hen.release(); //release the object, pointer no longer points to that object??



	hen.reset(); //this will delete the owned object
	hen.reset(ptr); //this is reset the pointer to the original hen object that was copy earlier

	//alternatively, we can call a function to return a smart pointer;
	auto hen3 = GetHen(2, 3.9f);

	//****SHARED_PTR

	auto sp = make_shared<int>(30);

	int copy = *sp;

	//int& ref = *sp;

	//int *ptr = sp.get();

	assert(!sp); //check if a pointer is not null
	assert(sp.use_count() == 0); //count how many times it shares the objct with other 
	assert(!sp.unique()); //check it's one-to-one pointer to object

	auto sp1 = make_shared<Hen>(5, 5.7f);

	assert(sp1);
	assert(sp1.use_count() == 1);
	assert(sp1.unique());

	auto sp2 = sp1;
	
	assert(sp1.use_count() == 2);
	assert(!sp1.unique());

	assert(sp2.use_count() == 2); //notice that sp2 and sp1 have same use_count and uniqueness
	assert(!sp2.unique()); 

	assert(sp1.get() == sp2.get());
	assert(sp1 == sp2);

	//*****WEAK_PTR

	//weak_ptr is used to point to a shared pointer
	auto weakPtr = weak_ptr<Hen>{ sp1 };

	assert(!weakPtr.expired());
	assert(weakPtr.use_count() == 1);

	if (auto locked = weakPtr.lock()) {
		cout << "locked" << std::endl;
	}

	sp1 = nullptr;

	assert(weakPtr.expired());
	assert(weakPtr.use_count() == 0);

	if (auto locked = weakPtr.lock()) {
		cout << "locked" << std::endl;
	}
	else {
		weakPtr.reset();
	}

	return 0;
}
