#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
  srand(time(NULL)); // This initializes the random generator.
  int rnd = 0;
  for (int i=0; i<20; i++) {
    rnd = rand() % 5; // generate a random number in the range [0, 4]
    try {
      switch (rnd) {
        case 0:
          throw 3.2f;
          break;
        case 1:
          throw double(43.56);
          break;
        case 3:
          throw "Abrakadabra";
          break;
        case 4:
          throw false;
          break;
        default:
          throw 12;
          break;
      }
    } catch (float x) {
// Write catch blocks for each possibly thrown exception.
// In each catch block write out what the exception's type was. And what the exceptions value was.
      cout << "Exception type: float; value: " << x << endl;
    } catch (double x) {
      cout << "Exception type: double; value: " << x << endl;
    } catch (char const* x) {
      cout << "Exception type: char const*; value: " << x << endl;
    } catch (bool x) {
      cout << "Exception type: bool; value: " << x << endl;
    } catch (int x) {
      cout << "Exception type: int; value: " << x << endl;
    }

  }

  return 0;
}
