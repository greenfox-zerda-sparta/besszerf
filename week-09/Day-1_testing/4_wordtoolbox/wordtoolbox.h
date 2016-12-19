#ifndef WORDTOOLBOX_H_
#define WORDTOOLBOX_H_
#include <cctype>
#include <algorithm>

#include <string>

using namespace std;

class WordToolbox {
  public:
    WordToolbox(string my_string);
    string getS();
    void setS(string x);
    bool isAnAnagram(string stringToCheck);
    int countHowMany(char charToFind);
  private:
    string stringHeld;
    string to_lower(string x);
};

#endif /* WORDTOOLBOX_H_ */
