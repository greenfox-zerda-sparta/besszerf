#include <iostream>
#include <string>
using namespace std;

// Define a function like macro that prints out the parameter it gets,
// and adds this string before it "DEBUG: " if __DEBUG is defined.
// Otherwise adds "RELEASE: " before the string.
// Use try it out. Illustrate that it works.

#ifdef __DEBUG
#define Str(a) "DEBUG: " #a
#else
#define Str(a) "RELEASE: " #a
#endif


int main() {
  cout << Str("XXX") << endl;

  return 0;
}
