#include <iostream>
#include <string>

using namespace std;

int main() {
	int j1 = 10;
	int j2 = 3;
	// tell if j1 is higher than j2 squared and smaller than j2 cubed
	j1>j2*j2 && j1< j2*j2*j2 && cout << "True";
	return 0;
}
