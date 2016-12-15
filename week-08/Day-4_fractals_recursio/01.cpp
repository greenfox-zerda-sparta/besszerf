#include <iostream>
#include <string>

using namespace std;

void count_down(int x) {
  if (x == 0) {
    cout << endl << "BUMMMMMMMMM!!!!!" << endl;
    return;
  } else {
    cout << x << " ";
    count_down(x - 1);
  }
}

int main() {
// write a recursive function
// that takes one parameter: n
// and counts down from n

  count_down(10);
  return 0;
}
