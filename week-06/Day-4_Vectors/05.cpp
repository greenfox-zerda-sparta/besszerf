#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
typedef unsigned int uint;

using namespace std;

int main() {
  //create a vector of integers with the size of 10, fill them with random numbers
  //create a vector of doubles and reserve place for 10 items
  //push and item to the end of the vector with the double places
  //print which vectors size is higher (and why?)
  vector<int> v(10);
  srand(time(NULL));
  for (uint i = 0; i < 10; i++) {
    v[i] = rand() %10;
  }
  vector<double> v2;
  v2.reserve(10);
  v2.push_back(3.1415);
  cout << " The size of " << (v.size() > v2.size()? "integer vector": "double vector") << " is biger." << endl;
  // Because when only reserving place, size don't change.
  return 0;
}
