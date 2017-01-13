#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

// Write a program that creates a text file named alice_words.txt
// containing an alphabetical listing of all the words,
// and the number of times each occurs, in the text version of
// Alice’s Adventures in Wonderland.
// (You can obtain a free plain text version of the book,
// along with many others, from http://www.gutenberg.org.)
//
// The first 10 lines of your output file should look something like this:
//
// Word              Count
// =======================
// a                 631
// a-piece           1
// abide             1
// able              1
// about             94
// above             3
// absence           1
// absurd            2
//
// How many times does the word alice occur in the book?
// What is the longest word in Alice in Wonderland?
// How many characters does it have?

void print_map(map<string, int>& names) {
  cout << " Word                   Count" <<  endl << " ============================" <<  endl;
  int chars_count = 0;
  string longest ="";
  for(map<string, int>::iterator it = names.begin(); it != names.end(); ++it) {
      cout << " " << it->first;
      if (it->first.length() > longest.length()) {
        longest = it->first;
      }
      int len = it->first.length();
      chars_count += len * it->second;
      for (int i = len; i < 30; ++i) {
        cout << " ";
      }
      cout << it->second << endl;
  }
  cout << endl << "Character count: " << chars_count <<endl;
  cout << "Longest word (length): " << longest << " (" << longest.length() << ")" << endl;
}

void clean_word(string& word) {
  unsigned int to_remove = 0;
  for(string::iterator i = word.begin(); i != word.end(); i++) {
    if (*i <65 || (*i > 90 && *i < 97) || *i > 122) {
      ++to_remove;
    } else {
      word.erase(word.begin(), word.begin() + to_remove);
      to_remove = 0;
      break;
    }
  }
  if (to_remove == word.length()) {
    word = "";
    return;
  }
  for(string::reverse_iterator i = word.rbegin(); i != word.rend(); i++) {
    if (*i <65 || (*i > 90 && *i < 97) || *i > 122) {
      ++to_remove;
    } else {
      word.erase(word.end() - to_remove, word.end());
      break;
    }
  }
  for(string::iterator i = word.begin(); i != word.end(); i++) {
    if (*i == 45 && *(i + 1) == 45) {
      word = "";
      return;
    }
  }
  transform(word.begin(), word.end(), word.begin(), ::tolower);
}

void sort_map() {

}
int main() {
  ifstream ifs("alice.txt");
  string word;
  map<string, int> alice_map;
  int wc = 0;
  while (ifs >> word) {
    ++wc;
    clean_word(word);
    if (word == "") {
      continue;
    }
    if ( alice_map.find(word) == alice_map.end() ) {
      alice_map[word] = 1;
    } else {
      ++alice_map[word];
    }
  }
  print_map(alice_map);
  cout << "Word 'alice' occurs this number times: " << alice_map["alice"] << endl;
  return 0;
}
