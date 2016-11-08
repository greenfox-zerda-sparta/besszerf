#include <iostream>
#include <string>
#include "pirate.h"

using namespace std;

int main() {
    // create a pirate class
    // it should have 2 methods
    // drink_rum()
    // hows_goin_mate()
    // if the drink_rum was called at least 5 times:
    // hows_goin_mate should return "Arrrr!"
    // "Nothin'" otherwise
  Pirate captain_hook;
  for (int i = 0; i < 5; i++) {
    captain_hook.drink_rum();
    cout << captain_hook.hows_goin_mate() << endl;
  }
  return 0;
}
