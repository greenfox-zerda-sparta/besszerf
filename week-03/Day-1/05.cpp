#include <iostream>

using namespace std;

int *resize (int *array, int size, int new_size) {
  int *pointer = NULL;
  pointer = new int[new_size];
  for (int i = 0; i < new_size; i++) {
    pointer[i] = (i < size ? array[i] : 0);
  }
   delete[] array;
  return pointer;
}

/**
 * Create a function called "resize" that takes a pointer to an int array, it's size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it should fill all the new slots with zeros.
 * It should delete the old array.
 */

int main() {
  int *array = new int[5];
  for (int i = 0; i < 5; i++) {
    array[i] = i;
  }
  int new_size = 8;
  int *new_array = resize(array, 5, new_size);
  for (int i = 0; i < new_size; i++) {
    cout << new_array[i] << " ";
  }
  delete[] new_array;
  return 0;
}
