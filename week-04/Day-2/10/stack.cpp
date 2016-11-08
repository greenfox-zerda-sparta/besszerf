#include "stack.h"

#include <iostream>
#include <string>

using namespace std;

// Construct
// It should dynamically allocate the Stack instance
// It should set the size
// It should dynamically allocate the double array

Stack::Stack(double input[], int size) {
  storage = new double[size];
  for (int i = 0; i < size; i++) {
    storage[i] = input[i];
  }
  this->size = size;
}

// Push
// It should push the value to the end of the stack
// It should increment the size by 1
// It should reallocate the array inside by the incremented size, and copy it's values

void Stack::push(double value) {
  size++;
  double* new_storage = new double[size];
  for (int i = 0; i < size - 1; i++) {
    new_storage[i] = storage[i];
  }
  new_storage[size-1] = value;
  delete[] storage;
  storage = new_storage;
}

// Pop
// It should return the value that was pushed the last time
// It should decrement the size by 1
// It should reallocate the array inside by the decremented size, and copy it's values

double Stack::pop() {
  if (size == 0) {
    return 0;
  }
  double result = storage[size-1];
  double* new_storage = new double[--size];
  for (int i = 0; i < size; i++) {
    new_storage[i] = storage[i];
  }
  delete[] storage;
  storage = new_storage;
  return result;
}

const int Stack::get_size() {
      return size;
    }


