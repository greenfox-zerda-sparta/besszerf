#include <iostream>
#include <string>

using namespace std;

int main() {
	// Write a program that prints the numbers from 1 to 100.
	// But for multiples of three print "Fizz" instead of the number
	// and for the multiples of five print "Buzz".
	// For numbers which are multiples of both three and five print "FizzBuzz".


	short b = 1;
	do {
		if (b % 3 == 0 && b % 5 == 0) {
			cout << "FizzBuzz" << endl;
		}else if (b % 3 == 0){
			cout << "Fizz" << endl;
		} else if (b % 5 == 0) {
			cout << "Buzz" << endl;
		} else {
			cout << b << endl;
		}
		b++;
	} while (b < 101);


	short a = 1;
	while (a < 101) {
		if (a % 3 == 0 && a % 5 == 0) {
			cout << "FizzBuzz" << endl;
		}else if (a % 3 == 0){
			cout << "Fizz" << endl;
		} else if (a % 5 == 0) {
			cout << "Buzz" << endl;
		} else {
			cout << a << endl;
		}
		a++;
	}

	for (int i = 1; i < 101; i++){
		if (i % 3 == 0 && i % 5 == 0) {
			cout << "FizzBuzz" << endl;
		}else if (i % 3 == 0){
			cout << "Fizz" << endl;
		} else if (i % 5 == 0) {
			cout << "Buzz" << endl;
		} else {
			cout << i << endl;
		}
	}
	return 0;
}
