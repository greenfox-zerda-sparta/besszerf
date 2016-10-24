#include <iostream>
#include <string>

using namespace std;

int main() {

	int input;


/*	I 		1-esek 1-3  + I
			4-es  5 ele I
			5-o:s: L
			6-8 L + I
			9 10-es -I

	II 		10 -es 1-3 +X
			50		L

	III		100 -as   C

	IV		1000 -es M
*/
	do {
		string out = "Roman number: ";
		cout << "Enter a number between 1 and 3999 (or press 'x' for exit): ";
		cin >> input;

		if (input < 1 && input > 3999){
			cout << "Your input is illegal" << endl;
			continue;
		}
		int ones = input % 10;
		int tens = (input - ones)%100;
		int hundreds = (input - ones - tens)%1000;
		int tous =  (input - ones - tens - hundreds)%10000;

		if (tous > 0) {
			for (short i = 1; i < tous; i++){
				out = out + "M";
			}
		}
		if (hundreds > 0 && hundreds < 4){
			for (short i = 1; i < hundreds; i++){
				out = out + "C";
			}
		}

	} while (input != 'x');

	cout << "Bye!" << endl;

	return 0;
}
