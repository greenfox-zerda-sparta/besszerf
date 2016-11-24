#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <algorithm>
typedef unsigned int uint;

using namespace std;

int num_of_divisors(int my_num) {
  int result = 2;
  int i = 2;
  int num = my_num;
  while (i < num) {
    if (my_num % i == 0) {
      num = my_num / i;
      result++;
      if (num != i) {
        result++;
      }
    }
    i++;
  }
  return result;
}

bool ascending_vector(int i, int j) {
   return i < j;
}

int main() {
  //find how much integer divisor 2400 has
  //create a vector of doubles, reserve place for the divisors of 2400
  //fill this places with random numbers from 0 to 2400
  //sort them in ascending order
  int x = num_of_divisors(2400);
  vector<double> v(x);
  for (int i = 0; i < x; i++) {
    v[i] = rand() %2400;
  }
  sort(v.begin(), v.end(), ascending_vector);
  for (uint i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
