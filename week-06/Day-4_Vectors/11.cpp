#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <algorithm>
typedef unsigned int uint;

using namespace std;

void increment_inner(vector<int>& my_v) {
  for (uint i = 0; i < my_v.size(); i++) {
    my_v[i]++;
  }

}

int main() {
  //create a vector of vector of integers
  //the inner vectors have 5 integers, all of them 0
  //the outer vector is holding 5 vector
  //create a function which increase the given inner vector elements by 1 (one inside vector, holding five 0)  int x = num_of_divisors(2400);
  vector<int> inner_v(5);
  vector<vector<int> > outer_v(5);
  for (uint i = 0; i < 5; i++) {
    outer_v[i] = inner_v;
  }
  increment_inner(outer_v[3]);
  vector<int> my_v = outer_v[3];
  for (uint i = 0; i < my_v.size(); i++) {
    cout << my_v[i] << " ";
  }
  return 0;
}
