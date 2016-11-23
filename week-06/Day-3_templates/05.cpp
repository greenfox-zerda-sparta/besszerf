#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;

template<class T, class P>
void print_longer_in_bytes(T val1, P val2) {
  if (sizeof(val1) == sizeof(val2)) {
    cout << val1 << " is stored on the same amount of bytes like  " << val2 << "." << endl;
    return;
  }
  if (sizeof(val1) > sizeof(val2)) {
    cout << val1 << " is stored on more bytes, than " << val2 << "." << endl;
    return;
  }
  cout << val2 << " is stored on more bytes, than " << val1 << "." << endl;
}

int main() {
  //Create a function template that takes 2 different typenames, and prints out
  //which one is stored in more bytes from then  int arrayI[] = {102, 3, 5};
  int i = 90000000;
  double j = 3.14;

  print_longer_in_bytes(i, j);
  return 0;
}
