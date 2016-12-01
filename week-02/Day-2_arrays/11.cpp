#include <iostream>
#include <string>

using namespace std;
inline string adda (string x) {
	return x + "a";
}

int main() {
	  string k = "kuty";
	  // write a function that gets a string as an input
	  // and appends an 'a' character to its end

	  cout << adda(k) << endl;

	  return 0;
}
