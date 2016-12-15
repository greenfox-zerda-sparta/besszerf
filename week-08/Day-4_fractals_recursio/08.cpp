#include <iostream>
#include <string>

using namespace std;

string remove_x(string word) {
  if (word.length() == 1) {
    if (word[0] != 'x') {
      return word;
    } else {
      return "";
    }
  }
  if (word[0] == 'x') {
    word = word.substr(1);
    return remove_x(word);
  }
  return word[0] + remove_x(word.substr(1));
}

int main() {
  // Given a string, compute recursively a new string where all the 'x' chars have been removed.
  cout << remove_x("Valamix tudxoma'nyos?") << endl;
  return 0;
}
