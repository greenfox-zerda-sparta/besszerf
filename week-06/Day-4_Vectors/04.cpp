#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
typedef unsigned int uint;

using namespace std;

void add_char(vector<char>& my_v, char x) {
  my_v.push_back(x);
}

int main() {
  //create a vector of chars with the size of zero;
  //write a function where the user can add characters to the end of this vector
  vector<char> v;
  srand(time(NULL));
  for (uint i = 0; i < 10; i++) {
    add_char(v, (char)rand() %26 + 64);
  }
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
