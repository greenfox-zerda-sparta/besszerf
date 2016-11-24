#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <algorithm>
typedef unsigned int uint;

using namespace std;

void print_vector(vector<vector<int> >& outer_v) {
  for (uint i = 0; i < outer_v.size(); i++) {
    for (uint j = 0; j < outer_v[i].size(); j++) {
      cout << outer_v[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  //Create a 2 dimensional vector with matrix!
  // 1 0 0 0
  // 0 1 0 0
  // 0 0 1 0
  // 0 0 0 1
  // Extend it to the following format:
  // 1 1 1 1 1
  // 0 1 0 0 1
  // 0 0 1 0 1
  // 0 0 0 1 1
  // 0 0 0 0 1
  // Mirror it horizontaly!
  // Mirror it verticaly!

  vector<vector<int> > outer_v(4);
  for (uint i = 0; i < outer_v.size(); i++) {
    outer_v[i] = vector<int>(4);
    for (uint j = 0; j < outer_v[i].size(); j++) {
      if (i == j) {
        outer_v[i][j] = 1;
        continue;
      }
    }
  }

  for (uint i = 0; i < outer_v.size(); i++) {
      outer_v[i].insert(outer_v[i].begin(), 0);
      outer_v[i][outer_v[i].size() - 1] = 1;
  }
  outer_v.insert(outer_v.begin(), vector<int>(5, 1));
  print_vector(outer_v);

  vector<vector<int> > my_v = outer_v;
// Mirroring horizontally
  for (uint i = 0; i < outer_v.size(); i++) {
    uint x = outer_v[i].size();
    for (uint j = 0; j < x; j++) {
      my_v[i][j] = outer_v[i][x -1 -j];
    }
  }
  outer_v = my_v;
  print_vector(outer_v);

// Mirroring vertically
  for (uint i = 0; i < my_v.size(); i++) {
      my_v[i] = outer_v[my_v.size() -1 - i];
  }
  outer_v = my_v;
  print_vector(outer_v);

  return 0;
}
