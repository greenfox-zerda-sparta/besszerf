#include "fibonacci.h"

unsigned int Fibonacci::get_number(uint index) {
  if (index == 0) {
    return 0;
  }
  if (index < 3) {
    return 1;
  }
  uint result;
  uint n1 = 1;
  uint n2 = 1;
  for (uint i = 3; i <= index; ++i) {
    result = n1 + n2;
    n2 = n1;
    n1 = result;
  }
  return result;
}

