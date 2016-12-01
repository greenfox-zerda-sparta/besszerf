#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Duplicate the Stack class from the previous exercies.
// Create a _base_class_ for Your exception.
// The class should have a private field:
// 1.) A field of type: in So You can give back the element which caused the problems.
// Set all the fields in the constructor only of the base class only..
// Create a get... method for this field. Again, in the base class only. This should not be virtual.
// Create a _virtual_ std::string toString() method, which is abstract (=0).
// Create a subclass for each possible exception type that might occur.
//
// - Demonstrate how this works in the main function. Print the error messages from the main function.
// - Don't forget to declare for each method what kind of exception they might be throwing.
// - You can order the consecutive catch blocks one after an other in more ways. Try them out.
// - Try out with the base class in the catch first.
// - Try out with the inherited classes in the first catch block.
// - Print out at the end of the main function in plain text, what You've learned about the importane of the order of the catch blocks.
// - Print out also what You've learned here about polymorphism.

enum Stack_state {FULL, EMPTY};

class StackExceptions : public exception{
  private:
    Stack_state type;
  public:
    StackExceptions(Stack_state& type);
    Stack_state get_type();
    virtual std::string toString() = 0;
};

StackExceptions::StackExceptions(Stack_state& type) {
  this->type = type;
}

Stack_state StackExceptions::get_type() {
  return type;
}

class FullStackE : public StackExceptions {
  public:
    FullStackE(Stack_state type);
    std::string toString();
};

FullStackE::FullStackE(Stack_state type) : StackExceptions(type) {}

std::string FullStackE::toString() {
  return "Stack is full.";
}

class EmptyStackE : public StackExceptions {
  public:
    EmptyStackE(Stack_state type);
    std::string toString();
};

EmptyStackE::EmptyStackE(Stack_state type) : StackExceptions(type) {}

std::string EmptyStackE::toString() {
  return "Stack is empty.";
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
    FullStackE my_exception(e);
    cout << my_exception.toString() << endl;
    cout << my_exception.get_type() << endl;
  }
  try {
    for (int i = 6; i > -1; i--) {
      cout << "Popped: "<< my_stack.pop() << endl;
    }
  } catch (Stack_state& e) {
    EmptyStackE my_exception(e);
    cout << my_exception.toString() << endl;
    cout << my_exception.get_type() << endl;
  }
  cout << "If I don't watch the correct order for try/catch blocks out the program doesn't make the desired output." << endl;
  cout << "If there is a virtual method (= 0) in the parent class, it can not invoked instantiate in main." << endl;
  return 0;
}
