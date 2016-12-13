#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int x) {
  cout << x << " | ";
}
// create a function that prints a vector using iterators
void print_vector(vector<int>& vec) {
  for_each(vec.begin(), vec.end(), print);
}

int main() {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  print_vector(v);
  return 0;
}
