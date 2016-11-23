#include <iostream>
#include <string>

using namespace std;

template<class T>
void print_first(T* array) {
  array[2] += array[0];
  for (int i = 0; i < 3; i++) {
    cout << array[i] << ", ";
  }
  cout << endl;
}

int main() {
  // create a function template that takes fix long array
  // and add the 1st element of it to the third

  int arrayI[] = {102, 3, 5};
  float arrayF[] = {3.1415, 2.1, 4.3};

  print_first(arrayI);
  print_first(arrayF);
  return 0;
}
