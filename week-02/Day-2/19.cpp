#include <iostream>
using namespace std;

bool is_prime(int a) {
  bool res = false;
  if ( a > 0 && a < 4) {
    res = true;
  } else if (a % 2 == 0){
    res = false;
  } else {
    res = true;
    for (int i = 3; i < a/2; i++) {
      if (a % i == 0){
        res = false;
        break;
      }
    }
  }
  return res;
}

int main(){
  int number = 121;
  // create a function that decides if a number is a prime number.
  // It should take a number as an argument and return true if it is prime and
  // false otherwise.
  cout << is_prime(number);

  return 0;
}
