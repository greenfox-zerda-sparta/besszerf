#include <iostream>
#include <string>

using namespace std;

string get_string(string word) {
  if (word.length() == 1) {
    return word;
  } else {
    if (word[0] == ' ' || word[1] == ' ') {
      return word[0] + get_string(word.substr(1));
    }
    return word.substr(0, 1) + "*" + get_string(word.substr(1));
  }
}

int main() {
  // Given a string, compute recursively a new string where all the
  // adjacent chars are now separated by a "*".
  cout << get_string("Valami tudoma'nyos?") << endl;
  return 0;
}
