#include <iostream>
#include <string>

using namespace std;

int main() {
	int ad = 6;
	// print the numbers till ad from 0
	short b = 0;
	do {
		cout << b << endl;
		b++;
	} while (b <= ad);


	short a = 0;
	while (a <= ad) {
		cout << a << endl;
		a++;
	}

	for (int i = 0; i <= ad; i++) {
		cout << i << endl;
	}

	return 0;
}
