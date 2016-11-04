#include <iostream>

using namespace std;

struct Stack{
  double* storage;
  int size;
};

// Construct
// It should dynamically allocate the Stack instance
// It should set the size
// It should dynamically allocate the double array

Stack* stack_construct(double input[], int size = 0) {
  Stack* new_stack = new Stack;
  new_stack->storage = new double[size];
  for (int i = 0; i < size; i++) {
    new_stack->storage[i] = input[i];
  }
  new_stack->size = size;
  return new_stack;
}

// Push
// It should push the value to the end of the stack
// It should increment the size by 1
// It should reallocate the array inside by the incremented size, and copy it's values

void stack_push(Stack& stack, double value) {
  double* new_storage = new double[++stack.size];
  for (int i = 0; i < stack.size; i++) {
    new_storage[i] = i < stack.size-1 ? stack.storage[i] : value;
  }
  delete[] stack.storage;
  stack.storage = new_storage;
  }

// Pop
// It should return the value that was pushed the last time
// It should decrement the size by 1
// It should reallocate the array inside by the decremented size, and copy it's values

double stack_pop(Stack& stack) {
  double result = stack.storage[stack.size-1];
  double* new_storage = new double[--stack.size];
  for (int i = 0; i < stack.size; i++) {
    new_storage[i] = stack.storage[i];
  }
  delete[] stack.storage;
  stack.storage = new_storage;
  return result;
}

// Is empty
// It should return true if the stack is empty and false otherwise

bool is_empty(Stack& stack) {
  return stack.size == 0;
}

int main() {
  double my_array[] = {0.1, 1.2, 2.2, 3.3, 4};
  Stack* my_stack = stack_construct(my_array, 5);
  cout << "Initial size of the stack: " << my_stack->size << endl;
  stack_push(*my_stack, 5.5);
  cout << "Size of the stack after pushing: " << my_stack->size << endl << "Popping the pushed value: ";
  cout << stack_pop(*my_stack) << endl;
  cout << "Size of the stack after popping: " << my_stack->size << endl;
  cout << "Is the stack empty: " << is_empty(*my_stack) << endl;
  delete[] my_stack->storage;
  delete my_stack;
  return 0;
}