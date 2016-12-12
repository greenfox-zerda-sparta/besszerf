#include <iostream>
#include <string>
using namespace std;

// In Your main function create an array of integers. 5 long.
// Fill it up with random numbers.
// For each number treat it as the radius of a circle.
// Calculate the circumference and the area of the circle with such a radius.
// Use preprocessor to define the MY_PI constant. Use this in th calculations.

#define MY_PI 3.1415

int main() {
  int my_array[5];
  for (int i = 0; i < 5; i++) {
    my_array[i] = rand() % 100;
    cout << i+1 << ". Circle - r = " << my_array[i] << endl;
    cout << " Circumfenence: " << 2*my_array[i]*MY_PI << endl;
    cout << " Area: " << my_array[i]*my_array[i]*MY_PI << endl;
  }

  return 0;
}
