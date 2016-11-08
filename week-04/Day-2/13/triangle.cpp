#include "triangle.h"

#include <iostream>
#include <string>

using namespace std;

Triangle::Triangle(int size) {
  this->size = size;
}

const void Triangle::print_triangle() {
  string temp = "*";
  string temp2;
  if (size % 2 == 0){
    temp2 = " ";
  } else {
    temp2 = "";
  }
  for (int i = 0; i < size; i++) {
    if (i < size/2 ) {
      for (int k = size/2; k > i; k-- ) {
        cout << ' ';
      }
      cout << temp << endl;
      temp += "**";
     } else {
       cout << temp2;
       temp2 += " ";
       for (int z = 0; z < size-i-1; z++) {
         cout << "**";
       }
       cout << "*"<< endl;
    }
  }
}
