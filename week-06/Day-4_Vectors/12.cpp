#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <algorithm>
typedef unsigned int uint;

using namespace std;

void increment_inner(vector<int>& my_v, int x) {
    my_v[x]++;

}

int main() {
  //create a vector of vector of integers
  //the inner vectors have 5 integers, all of them 0
  //the outer vector is holding 5 vector
  //create a function which increase a specific element of an inner vector by 1
  vector<int> inner_v(5);
  vector<vector<int> > outer_v(5);
  for (uint i = 0; i < 5; i++) {
    outer_v[i] = inner_v;
  }
  increment_inner(outer_v[3], 2);
  vector<int> my_v = outer_v[3];
  for (uint i = 0; i < my_v.size(); i++) {
    cout << my_v[i] << " ";
  }
  return 0;
}
