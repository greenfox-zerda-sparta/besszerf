#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;

template<class T>
double get_sum(T* array, uint size) {
  T sum = T();
  for (uint i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

template<>
double get_sum<char> (char* m_str, uint size) {
  int sum = 0;
  for (uint i = 0; i < size; i++) {
    if (m_str[i] > 96 && m_str[i] < 123) {
      sum += m_str[i] - 96;
    } else if (m_str[i] > 64 && m_str[i] < 91) {
      sum += m_str[i] - 64;
    }
  }
  return sum;
}

int main() {
  // Create a function template that takes an array, and its length and return the sum of it elements
  // Create a template specialization for char types, that it returns the sum of the characters integer position
  // in the alphabet
  int arrayI[] = {102, 3, 5};
  float arrayF[] = {3.1415, 2.1, 4.3};
  char str[] = "Feed the monkey";
  cout << get_sum(arrayI, sizeof(arrayI)/sizeof(arrayI[0]))<< endl;
  cout << get_sum(arrayF, sizeof(arrayF)/sizeof(arrayF[0]))<< endl;
  cout << get_sum(str, 18)<< endl;
  return 0;
}
