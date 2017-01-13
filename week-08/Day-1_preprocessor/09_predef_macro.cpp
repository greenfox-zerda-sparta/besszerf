#include <iostream>
#include <string>
using namespace std;

// Create a function like macro. The Macro should take one parameter and
// print out the parameter to the console after printing out in which file
// and at which line it has been called at.
#define myAssert(a) {cout << "File: \""<< __FILE__ << "\"; line: " << __LINE__ << "; Parameter = " << (a) << endl;}

int main() {
  myAssert(3);
  return 0;
}
