#include <iostream>
#include <string>

using namespace std;

int main() {
	string x = "cheese";
	// Tell if the x has even or odd number of
	// characters with a True for even and
	// false False output otherwise
	if (x.length()%2 == 0){
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
