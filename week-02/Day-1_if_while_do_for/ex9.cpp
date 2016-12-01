#include <iostream>
#include <string>

using namespace std;

int main() {
	long i = 1357988018575474;
	// tell if it has 11 as a divisor
	if (i % 11 == 0) {
		cout << "11 is a divisor of i";
	} else {
		cout << "11 is not a divisor of i";
	}
	return 0;
}
