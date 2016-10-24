#include <iostream>
#include <string>

using namespace std;

int main() {
	string x = "monkey";
	// if the string is longer than 4 characters***
	// print 'Long!' otherwise print 'Short!'
	if (sizeof(x) > 4){
		cout << "Long" << endl;
	} else {
		cout << "Short" << endl;
	}
	return 0;
}