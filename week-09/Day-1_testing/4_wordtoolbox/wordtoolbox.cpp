#include "wordtoolbox.h"

WordToolbox::WordToolbox(string my_string) :
  stringHeld(my_string) {}

string WordToolbox::getS() {
  return stringHeld;
}

void WordToolbox::setS(string x) {
  stringHeld = x;
}

int WordToolbox::countHowMany(char c) {
  int result = 0;
  for (uint i = 0; i < stringHeld.length(); ++i) {
    if (stringHeld[i] == c) {
      ++result;
    }
  }
  return result;
}

bool WordToolbox::isAnAnagram(string x) {
  string temp = stringHeld;
  sort(temp.begin(), temp.end());
  sort(x.begin(), x.end());
  return to_lower(temp) == to_lower(x);
}

string WordToolbox::to_lower(string x){
  int i=0;
  char c;
  while (x[i])
  {
    c=x[i];
    putchar (tolower(c));
    i++;
  }
  return x;
}
