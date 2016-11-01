#include <iostream>
#include <string>

using namespace std;

string CreatePalindrome(string phrase) {
  string res = phrase;
  for (int i = phrase.length()-1; i >= 0; i--) {
    res += phrase[i];
  }
  return res;
}
bool is_palindrome(string x) {
  bool res = false;
  int len = x.length();
  int middle = len/2;
  string middle_part = "";
  if (len % 2 == 1) {
    middle_part = x[middle];
  }
  string first_part = "";
  string last_part = "";
  for (int i = 0; i < middle; i++) {
    first_part += x[i];
  }
  for (int i = middle-1; i >= 0; i--) {
    last_part += x[i];
  }

  if (first_part + middle_part + last_part == x) {
    res = true;
  }

  return res;
}

string SearchPalindromes(string phrase) {
  string res = "[";
  int p_len = phrase.length();
  string candidate = "";
  int skip;
  bool first = true;
  for (int i = 0; i < p_len-2; i++) {
    skip = 0;
    candidate = phrase[i];
    candidate += phrase[(i + 1)];
    for (int j = 2; i+j < p_len; j++ ) {
      candidate += phrase[(i+j)];
      if (is_palindrome(candidate)) {
        if (candidate.length() > 3) {
          skip = (candidate.length() - 2) /2;
          i += skip;
        }
        if (!first) {
          res += ", ";
        }
        first = false;
        res += "'" + candidate + "'";
      }
    }
  }
  res += "]";
  return res;
}

int main() {
  // Create a function that takes a string and creates a palindrome from it. It should work like this:
  string output = CreatePalindrome("pear");
  cout << output << endl; // it prints: pearraep

  //Create a function that searches for all the palindromes in a string that are at least than 3 characters, and returns a list with the found palindromes. Example:
  output = SearchPalindromes("dog goat dad duck doodle never");
  cout << output << endl; // it prints: ['og go', ' dad ', 'd d', 'dood', 'eve']
  return 0;
}
