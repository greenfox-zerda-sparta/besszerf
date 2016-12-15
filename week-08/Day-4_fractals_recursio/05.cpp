#include <iostream>
#include <string>

using namespace std;

int count_ears(int x) {
  if (x == 1) {
    return 2;
  } else {
    return 2 + count_ears(x - 1);
  }
}

int main() {
  // We have a number of bunnies and each bunny has two big floppy ears.
  // We want to compute the total number of ears across all the bunnies
  // recursively (without loops or multiplication).
  cout << count_ears(10) << endl;
  return 0;
}
