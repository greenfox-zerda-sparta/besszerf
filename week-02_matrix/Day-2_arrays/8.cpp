#include <iostream>
#include <string>

using namespace std;

int main() {
	  int h[] = {3, 4, 5, 6, 7};
		// print the sum of all numbers in h
	  int sum = 0;
	  for (int i = 0; i < sizeof(h)/4; i++){
			sum+= h[i];
		}
		cout << sum << endl;

	  return 0;
}
