#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Duplicate the Stack class from the previous exercies.
// Create a class for Your exception.
// The class should have two private fields:
// 1.) A filed from Your enum type to represent the kind of error.
// 2.) A field of type: int. So You can give back the element or the index which caused the problems.
// Set all the fields in the constructor only.
// Create get... methods for both variables.
// Create an std::string toString() method, which gives back a comprehensive error message.
//
// Demonstrate how this works in the main function. Print the error messages from the main function.
enum Stack_state {FULL, EMPTY};

class StackExceptions : public exception{
  private:
    Stack_state type;
    int index;
  public:
    StackExceptions(Stack_state& type);
    Stack_state get_type();
    int get_index();
    std::string toString();
};

StackExceptions::StackExceptions(Stack_state& type) {
  this->type = type;
  index = (int)type;
}

string StackExceptions::toString() {
 if (type == EMPTY) {
   return "Stack is empty.";
 }
 return "Stack is full.";
}

Stack_state StackExceptions::get_type() {
  return type;
}

int StackExceptions::get_index() {
  return index;
}

class Stack{
  private:
    double* storage;
  int size;
  public:
    void push(double element) throw (Stack_state);
    double pop() throw (Stack_state);
    Stack();
    ~Stack();
    string interpretException(Stack_state exception);
};

Stack::Stack() {
  storage = new double[5];
  size = 0;
}

Stack::~Stack() {
  delete[] storage;
}

void Stack::push(double element) throw (Stack_state){
  if (size == 5) {
    throw FULL;
  }
  storage[size] = element;
  size++;
}

double Stack::pop() throw (Stack_state){
  if (size == 0) {
     throw EMPTY;
  }
  size--;
  return storage[size];
}

int main() {
  Stack my_stack;
  try {
    for (int i = 0; i < 6; i++) {
      my_stack.push(i);
      cout << "Pushed: "<< i << endl;
    }
  } catch (Stack_state& e) {
    StackExceptions my_exception(e);
    cout << my_exception.toString() << endl;
    cout << my_exception.get_type() << endl;
    cout << my_exception.get_index() << endl;
  }
  try {
    for (int i = 6; i > -1; i--) {
      cout << "Popped: "<< my_stack.pop() << endl;
    }
  } catch (Stack_state& e) {
    StackExceptions my_exception(e);
    cout << my_exception.toString() << endl;
    cout << my_exception.get_type() << endl;
    cout << my_exception.get_index() << endl;
  }
  return 0;
}
