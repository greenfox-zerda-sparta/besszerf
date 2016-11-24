#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
typedef unsigned int uint;

using namespace std;

int main() {
  //Create a vector of integers
  //reserve place for 10 element, then fill those place with random numbers between 0 and 10
  vector<int> v;
  v.reserve(10);
  for (uint i = 0; i < 10; i++) {
    v.push_back(rand() %10);
  }
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
