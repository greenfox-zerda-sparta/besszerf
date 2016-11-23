#include <iostream>
#include <string>

using namespace std;

template<class T>
void print_first(T& array) {
  cout << array[0] << endl;
}

int main() {
	// create a function template the takes in a fix long array and prints the 1st element of it
  int arrayI[] = {102, 3, 5};
  float arrayF[] = {3.1415, 2.1, 4.3};

  print_first(arrayI);
  print_first(arrayF);
  return 0;
}
