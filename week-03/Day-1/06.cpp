#include <iostream>

using namespace std;

int *filter_greater_than_5(int *array, int size) {
  int *pointer = NULL;
  int size_of_new_array = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] > 5) {
      size_of_new_array++;
    }
  }
  pointer = new int[size_of_new_array];
  int k = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] > 5) {
      pointer[k] = array[i];
      k++;
    }
  }

  return pointer;
}

/**
 * Create a function called "fliter_greater_than_5" that takes a pointer to an int array, and it's size.
 * It should return a pointer to a new array that only consists the numbers that are bigger than 5.
 */

int main() {
  int *ar = new int[5];
  for (int i = 0; i < 5; i++) {
    ar[i] = 3 + i;
  }
  int *array = filter_greater_than_5(ar, 5);
  delete[] ar;
  for (int i = 0; i < 2; i++) {
    cout << array[i] << " ";
  }
  delete[] array;
  return 0;
}
