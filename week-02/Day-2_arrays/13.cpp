#include <iostream>
#include <string>

using namespace std;

inline int fact (int x) {
	if (x == 1) {
		return 1;
	} else {
		return x*fact(x-1);
	}
}

int main() {
	  // create a function that returns it's input factorial

	  int x = 5;
	  cout << fact(x) << endl;

	  return 0;
}
