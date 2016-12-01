#include "square.hpp"

#include <iostream>
#include <string>

using namespace std;

string* Square::getName() {
  return new string("Square");
}
