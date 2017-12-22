//not every language have multiple inheritance
//MI refers to a class that is derived from more than one class (classes that are unrelated to the others) 

#include <iostream>
using namespace std;

class A {
    
    public:
    A() { cout << "A::A()" << endl; }
    virtual void displayA() {
        cout << "A::displayA()" << endl;
    }
};

class B {
   
    public:
    B() { cout << "B::B()" << endl; }
    void displayB() {
        cout << "B::displayB()" << endl;
    }
;

//by default it is private, if we forgot we cannot access anything from base class
class C : public A, public B {
     
     public:
     C() : A(), B() { cout << "C()"; }
     void displayA {
         cout << "C::diplayA()" << endl;
     }
     void displayB {
         cout << "C::displayB()" << endl;
     }
     
     
};
    
class Z {

    
 };

int main () {

     C instanceC;
     instanceC.displayA(); //C::displayA will be call, shawdowing from class A
     instanceC.A::displayA(); //A::displayA will be call, specifying
     instanceC.displayB(); //C::displayB will be call, shadowing
     
     //ptrvirtual enable pointer will be created if we enable polymorphism
    
    A* theIntance = new C;
    the instance->display();
    
    //problem with multiple inheritance
    
     return 0;
}
