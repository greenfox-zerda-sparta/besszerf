#include <iostream>
using namespace std;

// Create a constatn using a prepocesor directive.
// Print it out to the console.
// Undefine it. And then redefine it with a new value.
// Print it out again.

#define _FLOAT 3.1415


int main() {
  cout << "1. Float: " << _FLOAT << endl;

  #undef _FLOAT
  #define _FLOAT 12.8
  cout << "2. Float: " << _FLOAT << endl;

  return 0;
}
