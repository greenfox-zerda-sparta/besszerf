#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
typedef unsigned int uint;

using namespace std;

int main() {
  //create a vector of characters with the size of 8
  //ask the user to fill this vector with characters one by one
  //at the end make sure the vector holds the letters of "GREENFOX"
  //so correct the user if he/she gives a different letter from the one we want them to give :)
  vector<char> v(8);
  char array[] = "GREENFOX";
  bool should_go;
  for (int i = 0; i < 8; i++) {
    cout << "Please enter a character with capital letter: ";
    should_go = false;
    while (!should_go) {
      cin >> v[i];
      if (v[i] != array[i]) {
        cout << "Not correct; try again (Hint: " << array[i] << "): ";
    }else {
      should_go = true;
    }
    }
  }
  for (uint i = 0; i < 8; i++) {
    if (v[i] != array[i]) {
      v[i] = array[i];
    }
  }
  cout << "Wow! You've thought ";
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << "!" << endl;
  return 0;
}
