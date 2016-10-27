#include <iostream>

using namespace std;

void reverseArray(int *a, int size) {
  int temp;
  for (int i = 0; i < size/2; i++) {
    temp = a[i];
    a[i] = a[size-1-i];
    a[size-1-i] = temp;
  }
 return;
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

  // Write a function that takes an array and its length than reverses the array
  int size = sizeof(array)/sizeof(int);
  reverseArray(array, size);
  for (int i = 0; i < size; i++) {
    cout << array[i];
  }
  return 0;
}
