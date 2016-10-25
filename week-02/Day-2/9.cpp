#include <iostream>
#include <string>

using namespace std;
void greet (string name);

int main() {
  string i = "Jozsi";
  // create a function that takes a string argument and greets it.
  greet(i);
  return 0;
}

void greet (string name) {
	  cout << "Hello " << name << "!" << endl;
	return;
}
