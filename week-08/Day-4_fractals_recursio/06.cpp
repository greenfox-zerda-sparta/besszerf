#include <iostream>
#include <string>

using namespace std;

int count_ears(int x) {
  if (x == 1) {
    return 2;
  } else {
    if (x % 2 == 0) {
      return 3 + count_ears(x - 1);
    } else {
      return 2 + count_ears(x - 1);
    }
  }
}

int main() {
  // We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
  // (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
  // have 3 ears, because they each have a raised foot. Recursively return the
  // number of "ears" in the bunny line 1, 2, ... n (without loops or
  // multiplication).
  cout << count_ears(2) << endl;
  return 0;
}
