#include <iostream>
#include <string>

using namespace std;

string change_z_to_y(string z) {
  if (z[0] == 'z') {
      z[0] = 'y';
  }
  if (z.length() == 1) {
    return z;
  } else {
    return z[0] + change_z_to_y(z.substr(1));
  }
}

int main() {
  // Given a string, compute recursively (no loops) a new string where all the
  // lowercase 'x' chars have been changed to 'y' chars.
  cout << change_z_to_y("Valamz tudoma'nyos?") << endl;
  return 0;
}

