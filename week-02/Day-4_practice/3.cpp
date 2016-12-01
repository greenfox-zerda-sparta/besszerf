#include <iostream>

using namespace std;

void swapValues(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int first = 12;
  int second = 54;

  int *a = &first;
  int *b = &second;

  swapValues(a, b);

  cout << "first: " << first << ", second> " << second << endl;

  // Write a function that takes two int pointers and swaps the values where the pointers point

  return 0;
}
