#include <iostream>
#include <string>

using namespace std;

inline int min (int x[], int len) {
	int actMin = x[0];
	int min = 0;

	for (int i = 0; i < len; i++){
		if (x[i] < actMin) {
			min = i;
			actMin = x[min];
		}
	}

	return x[min];
}

int main() {
	  int numbers[] = {7, 5, 8, -1, 2};
	  // Write a function that takes an array and its length returns the minimal element
	  // in the array (your own min function)

	  cout << min(numbers, sizeof(numbers)/4) << endl;

	  return 0;
}

