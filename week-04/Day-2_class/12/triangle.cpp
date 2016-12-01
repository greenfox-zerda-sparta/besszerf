#include "triangle.h"

#include <iostream>
#include <string>

using namespace std;

Triangle::Triangle(int size) {
  this->size = size;
}

const void Triangle::print_triangle() {
  string temp = "*";
  for (int i = 0; i < size; i++) {
    for (int k = size; k > i; k-- ) {
      cout << ' ';
    }
    cout << temp << endl;
    temp += "**";
  }
}
