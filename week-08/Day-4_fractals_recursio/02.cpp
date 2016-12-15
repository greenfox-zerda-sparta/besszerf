#include <iostream>
#include <string>

using namespace std;

int add_nums_up_to(int x) {
  if (x == 0) {
    return x;
  } else {
    return x + add_nums_up_to(x - 1);
  }
}

int main() {
  // write a recursive function
  // that takes one parameter: n
  // and adds numbers from 1 to n
  cout << add_nums_up_to(10) << endl;
  return 0;
}
