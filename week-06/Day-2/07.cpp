#include <iostream>
#include <string>
using namespace std;

// Write a function that can throw two kinds of exceptions: int and const char*
// It should receive an integer.
// It should return a string from the char* array defined below.
// If the integer is larger than 5, throw an integer exception. The value of the exception should be how much larger it is.
// If the integer is less than 0, it should throw a const char* exception stating, that it is a negative number.
//
// Illustrate both cases in the main function.
// HINT: Put each protected code segmetn in a new try-catch block.

const char* sentence[6] = {"What", "a", "pleasant", "surprise", "this", "is."};

string get_string(int x) throw (int, const char*) {
  if (x > 5) {
    throw x-5;
  }
  if (x < 0) {
    throw "Negative number.";
  }
  string result = "";
  int size = sizeof(sentence)/sizeof(char*);
  for (int i = 0; i < size; i++) {
    result += sentence[i];
    if (i != size -1) {
      result += " ";
    }
  }
  return result;
}

int main() {
  try {
    cout << "It works: " << endl;
    cout << get_string(4) << endl;
    cout << "it does not work: " << endl;
    cout << get_string(-3) << endl;
  } catch (char const* x) {
      cout << x << endl;
  }try {
    cout << get_string(9) << endl;
  } catch (int x) {
    cout << "Number is: " << x << endl;
  }
  return 0;
}
