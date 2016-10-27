#include <iostream>

using namespace std;

bool containsNegativeNumber(int *a, int size) {
  bool result = false;
  for (int i = 0; i < size; i++) {
    if (a[i] < 0) {
      result = true;
      break;
    }
  }
  return result;
}

int main() {
  int numbers[] = {6, 5, -3, 4, -1, 8, 7};

  // Write a function that decides if an array includes at least one negative number or not
  int size = sizeof(numbers)/sizeof(int);
  cout << containsNegativeNumber(numbers, size) << '\n';

  return 0;
}
