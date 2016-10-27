#include <iostream>
#include <string>

using namespace std;

void squareOfNumbersInArray(int *a, int size) {
  for (int i = 0; i < size; i++) {
    *a *= *a;
    a++;
  }
 return;
}

int main() {
  // Write a function that takes an array and squares all the elements in the array
  int array[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(array)/sizeof(int);
  squareOfNumbersInArray(array, size);
  for (int i = 0; i < size; i++) {
    cout << array[i] << '\n';
  }
  return 0;
}
