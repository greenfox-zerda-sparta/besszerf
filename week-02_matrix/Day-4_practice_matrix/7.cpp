#include <iostream>

using namespace std;

void makeTriangle(int x) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < i+1; j++) {
      cout << '*';
    }
    cout << endl;
  }
 return;
}

int main() {
  // create a function that takes a number and prints a triangle like this:
  // *
  // **
  // ***
  // ****
  // *****
  // ******
  //
  // The triangle should have as many lines as the value in the argument
  makeTriangle(8);
  return 0;
}
