#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
typedef unsigned int uint;

using namespace std;

void do_magic(vector<int>& vec) {
  for (uint i = 0; i < vec.size(); i++) {
    if (vec[i] % 2 == 0) {
      vec.erase(vec.begin() + i);
      i--;
    }
  }
}

int main() {
  //create a vector of integers with the size of 20
  //fill this vector with random numbers from 0 to 10
  //print the items of the vector
  //remove the even numbers, then print the items again
  vector<int> v(20);
  v.reserve(10);
  for (uint i = 0; i < v.size(); i++) {
    v[i] = rand() %10;
  }
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  do_magic(v);
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
