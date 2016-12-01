#include <iostream>
#include <string>
using namespace std;

// Duplicate the Stack class from the previous exercies.
// Rewrite it so, that the push and pop methods don't throw integers.
// Define an enum for te two types of exceptions.
// Adapt the interpretException method to except an argument from that enum type.
// Adapt the main function so that the try and catch blocks except an exception of that enum type.
enum Stack_state {FULL, EMPTY};

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

string Stack::interpretException(Stack_state exception) {
 if (exception == EMPTY) {
   return "Stack is empty.\n";
 }
 return "Stack is full.\n";
}

int main() {
  Stack my_stack;
  try {
    for (int i = 0; i < 6; i++) {
      my_stack.push(i);
      cout << "Pushed: "<< i << endl;
    }
  } catch (Stack_state& e) {
    cout << my_stack.interpretException(e) << endl;
  }
  try {
    for (int i = 6; i > -1; i--) {
      cout << "Popped: "<< my_stack.pop() << endl;
    }
  } catch (Stack_state& e) {
    cout << my_stack.interpretException(e) << endl;
  }
  return 0;
}
