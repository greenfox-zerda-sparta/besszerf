#include <iostream>
#include <string>

using namespace std;

int main() {

	cout << "Hi! Let's see the roman numbers!" << endl << endl;
	int input;
	do {
		string out = "Roman number: ";
		cout << "Enter a number between 1 and 3999 (or -1 for exit): ";
		cin >> input;

		if (input == -1){
			break;
		} else if (input < 1 || input > 3999){
			cout << "Your input is invalid" << endl;
			continue;
		}

		int tous = 0, hundreds = 0, tens = 0;
		if (input >= 1000) {
			tous = input / 1000;
			input = input % (tous * 1000);
		}
		if (input >= 100) {
			hundreds = input / 100;
			input = input % (hundreds * 100);
		}
		if (input >= 10) {
			tens = input / 10;
			input = input % (tens * 10);
		}
		int ones = input;


		if (tous > 0) {
			for (short i = 0; i < tous; i++){
				out = out + "M";
			}
		}
		if (hundreds > 0 && hundreds < 4){
			for (short i = 0; i < hundreds; i++){
				out = out + "C";
			}
		} else if (hundreds == 4){
			out = out + "CD";
		} else if (hundreds == 5){
			out = out + "D";
		} else if (hundreds > 5 && hundreds < 9){
			out = out + "D";
			for (short i = 0; i < hundreds -5; i++ ){
				out = out + "C";
			}
		} else if (hundreds == 9){
			out = out + "CM";
		}
		if (tens > 0 && tens < 4){
			for (short i = 0; i < tens; i++){
				out = out + "X";
			}
		} else if (tens == 4){
			out = out + "XL";
		} else if (tens == 5){
			out = out + "L";
		} else if (tens > 5 && tens < 9){
			out = out + "L";
			for (short i = 0; i < tens -5; i++ ){
				out = out + "X";
			}
		} else if (tens == 9){
			out = out + "XC";
		}
		if (ones > 0 && ones < 4){
			for (short i = 0; i < ones; i++){
				out = out + "I";
			}
		} else if (ones == 4){
			out = out + "IV";
		} else if (ones == 5){
			out = out + "V";
		} else if (ones > 5 && ones < 9){
			out = out + "V";
			for (short i = 0; i < ones -5; i++ ){
				out = out + "I";
			}
		} else if (ones == 9){
			out = out + "IX";
		}
		if (input != -1) {
			cout << out << endl;
		}

	} while (input != -1);

	cout << "Bye!" << endl;
	return 0;
}
