#include <iostream>

using namespace std;

void fillArrayWithNumbers(int *a, int size) {
  for (int i = 0; i < size; i++) {
    *a = i;
    a++;
  }
 return;
}


int main() {
  int array[10];

  // write a function that takes an array and a length and it fills the array
  // with numbers from zero till the length
  int size = sizeof(array)/sizeof(int);
  fillArrayWithNumbers(array, size);
  for (int i = 0; i < size; i++) {
    cout << array[i];
  }
  return 0;
}
