#include <iostream>
#include <string>

using namespace std;

int main() {
	int f[] = {3, 4, 5, 6, 7};
	// Please double all the elements, than print all of them	e[2]++;

	for (int i = 0; i < sizeof(f)/4; i++){
		f[i] *= 2;
	}
	for (int i = 0; i < sizeof(f)/4; i++){
		cout << f[i] << endl;
	}
  return 0;
}
