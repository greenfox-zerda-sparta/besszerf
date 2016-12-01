#include "stack.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create a `Stack` class that stores elements
    // It should have a `size` method that returns number of elements it has
    // It should have a `push` method that adds an element to the stack
    // It should have a `pop` method that returns the last element form the stack and also deletes it from it

// Is empty
// It should return true if the stack is empty and false otherwise


  double my_array[] = {0.1, 1.2, 2.2, 3.3, 4};
  Stack my_stack(my_array, 5);
  cout << "Initial size of the stack: " << my_stack.get_size() << endl;
  my_stack.push(5.5);
  cout << "Size of the stack after pushing: " << my_stack.get_size() << endl << "Popping the pushed value: ";
  cout << my_stack.pop() << endl;
  cout << "Size of the stack after popping: " << my_stack.get_size() << endl;
  return 0;
}
