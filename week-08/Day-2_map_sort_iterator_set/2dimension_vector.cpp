#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> col;
typedef vector<col> floor;

int main() {
  floor one = floor(3, col(4, 1));
  for (floor::iterator it = one.begin(); it != one.end(); it++) {
    for (col::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++) {
      cout << *it2 << endl;
    }
  }
  return 0;
}
