#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;

template<class T>
void print_first(T* array, uint size) {
  for (uint i = 0; i < size; i++) {
    cout << array[i] << ", ";
  }
  cout << endl;
}

int main() {
  // create a function template which takes in an array, and the size of it
  // print all the elements of the array

  int arrayI[] = {102, 3, 5};
  float arrayF[] = {3.1415, 2.1, 4.3};

  print_first(arrayI, sizeof(arrayI)/sizeof(arrayI[0]));
  print_first(arrayF, sizeof(arrayI)/sizeof(arrayI[0]));
  return 0;
}
