#include <iostream>
#include <string>

using namespace std;

int numOfTwoEvens(int *a, int size) {
  int result = 0;
  for (int i = 1; i < size; i++) {
    if (a[i] % 2 == 0 && a[i-1] % 2 == 0) {
      result += 1;
    }
  }
  return result;
}

int main() {
  int numbers[] = {5, 2, 6, 3, 4, 8, 5, 2, 2, 2};

  // Write a function that counts how many times is an even number is folowed by
  // another even number in an array
  int size = sizeof(numbers)/sizeof(int);
  cout << numOfTwoEvens(numbers, size);
  return 0;
}
