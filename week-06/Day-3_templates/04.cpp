#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;

template<class T>
void sort_descending(T* array, uint size) {
  T temp;
  bool array_is_changed;
  do {
    for (uint i = 0; i < size - 1; i++) {
      array_is_changed = false;
      if (array[i+1] > array[i]) {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        array_is_changed = true;
      }
    }
  } while (array_is_changed);
}

int main() {
  // create a function template that takes an array and sort it in a descending order
  int arrayI[] = {102, 3, 5};
  float arrayF[] = {3.1415, 2.1, 4.3};

  sort_descending(arrayI, sizeof(arrayI)/sizeof(arrayI[0]));
  sort_descending(arrayF, sizeof(arrayI)/sizeof(arrayI[0]));
  for (uint i = 0; i < 3; i++) {
    cout << arrayI[i] << ", ";
  }
  cout << endl;
  for (uint i = 0; i < 3; i++) {
    cout << arrayF[i] << ", ";
  }
  cout << endl;
  return 0;
}
