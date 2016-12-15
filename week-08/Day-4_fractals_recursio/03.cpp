#include <iostream>
#include <string>

using namespace std;

int sum_of_digits(int x) {
  if (x/10 == 0) {
    return x;
  } else {
    return x%10 + sum_of_digits(x/10);
  }
}

int main() {
  // Given a non-negative int n,
  // return the sum of its digits recursively (no loops).
  // Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6),
  // while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
  cout << sum_of_digits(19740416) << endl;
  return 0;
}
