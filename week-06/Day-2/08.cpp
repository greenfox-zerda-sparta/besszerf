#include <iostream>
#include <string>
using namespace std;

// Create a fixed size stack. The stack can contain only 5 elements.
// You can push on the stack and pop from the stack.
// Write the push and pop methods so, that each throws an integer value if there is an error.
// Like when the stack is empty or full. Just make sure those are different values.
// Write a method called string interpretException(int exception) that returns the error message string for the integer.
//
// Illustrate in the main function both when it works fine and when exceptions occur.

class Stack{
  private:
    double* storage;
  int size;
  public:
    void push(double element) throw (int);
    double pop() throw (int);
    Stack();
    ~Stack();
    string interpretException(int exception);
};

Stack::Stack() {
  storage = new double[5];
  size = 0;
}

Stack::~Stack() {
  delete[] storage;
}

void Stack::push(double element) throw (int) {
  if (size == 5) {
    throw 1;
  }
  storage[size] = element;
  size++;
}

double Stack::pop() throw (int) {
  if (size == 0) {
    throw -1;
  }
  size--;
  return storage[size];
}

string Stack::interpretException(int exception) {
 if (exception == -1) {
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
  } catch (int e) {
    cout << my_stack.interpretException(e) << endl;
  }
  try {
    for (int i = 6; i > -1; i--) {
      cout << "Popped: "<< my_stack.pop() << endl;
    }
  } catch (int e) {
    cout << my_stack.interpretException(e) << endl;
  }
  return 0;
}
