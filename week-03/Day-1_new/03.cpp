#include <iostream>

using namespace std;

int main() {
  int* pointer = NULL;
  /**
   * Please create a program that asks for a count when it starts.
   * It should ask for a number count times, then it shoud print the average of the nubmers.
   * It should delete any dynamically allocated resource before the program exits.
   */
  float average = 0;
  cout << "Enter how many integers you gonna count with: ";
  int times;
  cin >> times;
  cout << endl;
  pointer = new int[times];
  for (int i = 0; i < times; i++) {
    cout << "Give me your integer number " << i + 1 << ": ";
    cin >> pointer[i];
    cout << endl;
    average += pointer[i];
  }
  average /= times;
  cout << "The average is: " << average;
  delete[] pointer;
  return 0;
}
