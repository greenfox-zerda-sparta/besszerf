#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
typedef unsigned int uint;

using namespace std;

void add_vector(vector<vector<int> >& vec, vector<int>& i_v) {
  vec.push_back(i_v);
}

int main() {
  //create a vector of vector of integers, yeah a vector that holds vectors of integers
  //the inner vectors have 5 integers, all of them 0
  //the outer vector is holding 5 vector at the begining
  //create a function that will add a new vector of integers to the end of our outer vector
  vector<int> inner_v(5);
  vector<vector<int> > outer_v(5);
  for (uint i = 0; i < 5; i++) {
    outer_v[i] = inner_v;
  }
  add_vector(outer_v, inner_v);
  cout << outer_v.size();
  return 0;
}
