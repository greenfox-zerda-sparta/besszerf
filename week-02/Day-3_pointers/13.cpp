#include <iostream>
#include <string>
using namespace std;

void printWordsOfStringInNewLine(string text) {
  for (int i = 0; i < text.length(); i++){
    if (text[i] == ' ') {
      cout << endl;
    } else {
      cout << text[i];
    }
  }
  cout << endl;
}

void putWordOfStringsInArray(string text, string *a, int size) {
  string temp = "";
  for (int i = 0; i < text.length(); i++){
    if (text[i] == ' ') {
      *a = temp;
      temp = "";
      a++;
    } else {
      temp += text[i];
    }
  }
  *a = temp;
}
// Create a function that prints each word in a string into a new line!
// Create an other function that takes a string and an array of strings as it's input
// and puts each word in the original string into a new element in the array of strings.
// Decide which argument should be a pointer and which shouldn't.
// In the main function, print out each element of the array into a new line!


int main(int argc, char **argv){

  string text = "Juli Joli Juci";
  string arr[3];
  int size = 3;
  printWordsOfStringInNewLine(text);
  putWordOfStringsInArray(text, arr, size);
  for (int i = 0; i < size; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}