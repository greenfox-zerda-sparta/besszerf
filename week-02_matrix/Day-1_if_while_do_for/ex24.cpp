#include <iostream>
#include <string>

using namespace std;

int main() {
	int ae = 4;
	string text = "Gold";
	// print content of the text variable ae times

	short b = 1;
	do {
		cout << text;
		b++;
	} while (b <= ae);


	short a = 1;
	while (a <= ae) {
		cout << text;
		a++;
	}

	for (short i = 0; i < ae; i++) {
		cout << text;
	}
	return 0;
}
