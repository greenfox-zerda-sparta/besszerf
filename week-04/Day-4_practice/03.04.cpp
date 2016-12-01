#include <iostream>
#include <string>
using namespace std;

// Create a class called ParentClass. It should have two public functions. Both return a string.
// One virtual, the other not.
// Each should return a unique string.
// Create a ChildClass which inherits from the ParentClass publicly.
// This should override both functions. The virtual and the nonvirtual one both.
// These should return unique string again.
//
// Create a main() function. In this function, create a ParentClass* pointer and instanciate a ChildClass
// member for that pointer.
// Hint: This should look something like this: ParentClass* a = new ChildClass();
// Print out the result of both functions on this a pointer.
// Print out the result of both functions if You first cast pointer a to be interpreted as of type ChildClass*
//

class Parent {
  public:
    string get_a_string();
    virtual string get_another();
    virtual ~Parent();
};

class Child : public Parent {
  public:
    string get_a_string();
    string get_another();
    ~Child();
};

string Parent::get_a_string() {
  return "Hi! I'm Parent. \n";
}

string Parent::get_another() {
  return "I'm Parent 2. \n";
}

Parent::~Parent() {}

string Child::get_a_string() {
  return "Hi! I'm the Child. \n";
}

string Child::get_another() {
  return "I'm Child 2. \n";
}

Child::~Child() {}


int main () {
  Parent* one = new Child();
  cout << one->get_a_string() << endl;
  cout << one->get_another() << endl;
  cout << ((Child*)one)->get_a_string() << endl;
  cout << ((Child*)one)->get_another() << endl;
  return 0;
}
