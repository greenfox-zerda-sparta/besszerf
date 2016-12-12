#include <iostream>
#include <string>
using namespace std;

// Create a function like macro, that get's one parameter.
// This macro should print out that paramter using cout.
// Illustrate that it works in Your main function.
#define Str(a) (a)

int main() {
    cout << Str(" Area: X") << endl;
  return 0;
}
