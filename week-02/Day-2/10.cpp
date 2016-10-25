#include <iostream>
#include <string>

using namespace std;
inline int doubleInt (int x) {
	return x*2;
}

int main() {
  int j = 123;
  // create a function that doubles it's input
  // double j with it
  cout << doubleInt(j) << endl;
  return 0;
}

