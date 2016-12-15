#include <iostream>
#include <string>

using namespace std;

int powN(int base, int power) {
  if (power == 0) {
    return 1;
  } else {
    return base * powN(base, power-1);
  }
}

int main() {
  // Given base and n that are both 1 or more, compute recursively (no loops)
  // the value of base to the n power, so powerN(3, 2) is 9 (3 squared).
  cout << powN(3, 3) << endl;
  return 0;
}
