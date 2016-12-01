#include <iostream>
#include <string>

using namespace std;

int main() {
	// print the even numbers till 20

	short b = 1;
	do {
		b % 2 == 1 && cout << b << endl;
		b++;
	} while (b < 21);


	short a = 1;
	while (a < 21) {
		a % 2 == 1 && cout << a << endl;
		a++;
	}

	for (short i = 1; i < 21; i++) {
		i % 2 == 1 && cout << i << endl;
	}
	return 0;
}
