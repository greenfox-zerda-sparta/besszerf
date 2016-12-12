#include <iostream>
using namespace std;

// Create a function like macro.
// It's job is to turn something written in code into a string.
// It should be called str(a).
// Try out the code below. See what happens!
#define str(a, b) ((a)>(b)?(a):(b))

int main() {
  int a = 22;
  int b = 24;
  if(a < b) {
    std::cout << str(a, b) << ";  a: " << a << "  b: " << b << std::endl;
  }
  return 0;
}
