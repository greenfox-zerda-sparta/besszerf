#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
typedef unsigned int uint;

using namespace std;

void do_magic(vector<double>& vec) {
  int x = rand() %vec.size();
  vec[x] += vec.back();
  vec.pop_back();
}

int main() {
  //create a vector of doubles with the size of 30, with every element equal of 1.5
  //create functions that takes this vector, pick the last element of it and adding its value to
  //an other item from the vector(this item place is random) and remove the last element at the end
  //run this function 20 times, then print every element of the vector
  vector<double> v(30, 1.5);
  srand(time(NULL));
  for (uint i = 0; i < 20; i++) {
    do_magic(v);
  }
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
