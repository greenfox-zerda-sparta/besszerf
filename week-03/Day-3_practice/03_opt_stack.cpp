#include <iostream>

using namespace std;

//Optimized Stack

//Implement a stack data-structure that stores doubles in C++, and several functions that operate on stacks.
// Each stack should have size property that stores how many elements are in the stack.
// The length of the inner array should be independent form the size, to optimize on reallocation,
// this case it does not need to reallocate each time on push.


struct Stack{
  double* storage;
  int size;
  int length_of_storage;
};

//Functions

//Construct
// It should dynamically allocate the Stack instance
// It should set the size
// It should dynamically allocate the double array
// The length of the allocated array should be independent from the size, to optimize on the reallocation of the array
// It should allocate at least a double length array then the size
// The length of the array should be always some power of two and at least 16 (16, 32, 64, 128, ...)

int set_size_of_storage(int comparing_value) {
  int optimal_size = 16;
  while (optimal_size < comparing_value) {
    optimal_size *= 2;
  }
  return optimal_size;
}

Stack* stack_construct(double input[], int size) {
  Stack* new_stack = new Stack;
  new_stack->length_of_storage = set_size_of_storage(size*2);
  new_stack->storage = new double[new_stack->length_of_storage];
  for (int i = 0; i < size; i++) {
    new_stack->storage[i] = input[i];
  }
  new_stack->size = size;
  return new_stack;
}

//Push
// It should push the value to the end of the stack
// It should increment the size by 1
//If the size exceeds the 80% of the current allocated length of the array it should reallocate
// the size of the array to it's double

void stack_push(Stack& stack, double value) {
  stack.storage[stack.size] = value;
  stack.size++;
  if (stack.length_of_storage * 0.8 < stack.size) {
    double* new_storage = new double[stack.length_of_storage * 2];
    for (int i = 0; i < stack.size; i++) {
      new_storage[i] = stack.storage[i];
    }
    stack.length_of_storage = stack.length_of_storage * 2;
    delete[] stack.storage;
    stack.storage = new_storage;
  }
}

// Pop
// It should return the value that was pushed the last time
// It should decrement the size by 1
// It should not resize the array

double stack_pop(Stack& stack) {
  stack.size--;
  return stack.storage[stack.size];
}

int main() {
  double my_array[] = {0.1, 1.2, 2.2, 3.3, 4, 5, 6, 7, 8, 9, 10};
  Stack* my_stack = stack_construct(my_array, 11);
  cout << "Initial size of the stack: " << my_stack->size << endl;
  cout << "Length of the storage array: " << my_stack->length_of_storage << endl;
  for (int i = 0; i < 15; i++) {
    stack_push(*my_stack, 5.5);
  }
  cout << "Size of the stack after pushing 15 elements: " << my_stack->size << endl << "Popping the pushed value: ";
  cout << stack_pop(*my_stack) << endl;
  cout << "Length of the storage array: " << my_stack->length_of_storage << endl;
  cout << "Size of the stack after popping: " << my_stack->size << endl;
  cout << "Length of the storage array: " << my_stack->length_of_storage << endl;
  delete[] my_stack->storage;
  delete my_stack;
  return 0;
}
