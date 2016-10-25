#include <iostream>
#include <string>

using namespace std;

inline int indOf (int x[], int len, int num) {
	int ind = -1;

	for (int i = 0; i < len; i++){
		if (x[i] == num) {
			ind = i;
			break;
		}
	}

	return ind;
}

int main() {
	  int numbers[] = {7, 5, 8, -1, 2};
	  // Write a function that takes ana array, its length and a number
	  // and it returns the index of the given number in the array.
	  // It should return -1 if did not find it. (linear search)

	  int num = -1;

	  cout << indOf(numbers, sizeof(numbers)/4, num) << endl;

	  return 0;
}

