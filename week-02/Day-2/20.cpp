#include <iostream>
#include <string>

using namespace std;

int get_number_of_char( char c, string w) {
  int res = 0;
  for (int i = 0; i < w.length(); i++) {
    if (w[i] == c) {
      res++;
    }
  }
  return res;
}

int main() {
  string word = "makkoshotyka-also";
  char letter = 'o';
  // Write a function that takes a string and a character, and counts how many
  // times the character occures in the string and it should return a number
  cout << get_number_of_char(letter, word) << endl;
  return 0;
}
