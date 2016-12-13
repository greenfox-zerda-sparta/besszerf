#include <iostream>
#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

map<char, int> create_map_from_string(string& text) {
  map<char, int> letters;
  for(unsigned int i =0; i < text.length(); i++) {
      if( letters.find(text[i]) == letters.end()) {
          letters[text[i]] = 1;
      } else {
          ++letters[text[i]];
      }
  }
  return letters;
}

// write a function that takes a string and returns a map
// the map should have the letters of the string as keys and
// it should have integers as values that represents how many times the
// letter appeared int the string

int main() {
  string text = "abrakadabramagic";
  map<char, int> letters = create_map_from_string(text);
  for(map<char, int>::iterator it = letters.begin(); it != letters.end(); ++it) {
      cout << it->first << " -> " << it->second << endl;
  }

  return 0;
}
