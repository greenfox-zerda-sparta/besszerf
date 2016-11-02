#include <iostream>

using namespace std;

int *range (int start, int end, int step) {
  int len_of_array = (end - start)/step;
  int* pointer = new int[len_of_array];
  int i = start;
  for (int j = 0; j < len_of_array; j++) {
      pointer[j] = i;
      i += step;
  }
  return pointer;
}

int main() {
  /**
   * Create a function called "range" that creates a new array and returns a pointer to it.
   * It should fill the array with numbers based on it's paramters.
   * It should take 3 paramters:
   * int from: the first number in the array
   * int to: it will fill the array till it would reach this number (so this number is not in the array)
   * int step: the step between the numbers
   *
   * Examples:
   * range(0, 10, 2) -> {0, 2, 3, 4, 5, 6, 8}
   * range(1, -8, -3) -> {1, -2, -5}
   *
   * It should delete any dynamically allocated resource before the program exits.
   */
  int begin = 2;
  int end = 8;
  int steps = 2;

  int *array = range(begin, end, steps);
  int array_len = (end - begin)/steps;
  for (int i = 0; i < array_len; i++) {
    cout << array[i] << "\n";
  }
  delete[] array;
  return 0;
}
