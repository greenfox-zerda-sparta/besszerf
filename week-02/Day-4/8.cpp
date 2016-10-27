#include <iostream>
#include <string>

using namespace std;

void printTriangle(int x) {
  string temp = "*";
  for (int i = 0; i < x; i++) {
    for (int k = x; k > i; k-- ) {
      cout << ' ';
    }
    cout << temp << endl;
    temp += "**";
  }
 return;
}

int main() {
  // Create a function that takes a number and prints a triangle like this:
  //
  //      *
  //     ***
  //    *****
  //   *******
  //  *********
  // ***********
  //
  // The triangle should have as many lines as the value in the argument
  printTriangle(8);
  return 0;
}
