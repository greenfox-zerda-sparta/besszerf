#include <iostream>
#include <string>

using namespace std;

void printDiamond(int x) {
  string temp = "*";
  string temp2;
  if (x % 2 == 0){
    temp2 = " ";
  } else {
    temp2 = "";
  }
  for (int i = 0; i < x; i++) {
    if (i < x/2 ) {
      for (int k = x/2; k > i; k-- ) {
        cout << ' ';
      }
      cout << temp << endl;
      temp += "**";
     } else {
       cout << temp2;
       temp2 += " ";
       for (int z = 0; z < x-i-1; z++) {
         cout << "**";
       }
       cout << "*"<< endl;
    }
  }
 return;
}

int main() {
  // Create a function that takes a number and prints a diamond like this:
  //
  //      *
  //     ***
  //    *****
  //   *******
  //  *********
  // ***********
  //  *********
  //   *******
  //    *****
  //     ***
  //      *
  //
  // The diamond should have as many lines as the value in the argument
  printDiamond(6);
  return 0;

  return 0;
}
