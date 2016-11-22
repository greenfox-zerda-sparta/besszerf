#include <iostream>
#include <string>
using namespace std;

// Write a function that receives a string and a character.
// The function should return an array of strings.
// The function should split the string at the character it receives as the second argument.
// The character it uses to split should not be in any of the new strings.
// Example: split("What a nice day", ' ');
// Result: {"What", "a", "nice",  "day"}
// If the character is not in the string throw an exception.
//
// In the main function demonstrate the function when working, and when throwing an exception.
// Write the results to the console.
string* my_split(string word_to_split, char delimiter) throw (const char*) {
  int array_length = 1;
  for (unsigned int i = 0; i < word_to_split.length(); i++) {
   if (word_to_split[i] == delimiter) {
     array_length++;
   }
  }
  if (array_length == 1) {
    throw "String does not contain the delimiter character.";
  }
  string* array = new string[array_length];
  int j = 0;
  for (unsigned int i = 0; i < word_to_split.length(); i++) {
     if (word_to_split[i] == delimiter) {
       j++;
       i++;
     }
     array[j] += word_to_split[i];
  }
  return array;
}

int main() {
  try {
    string* my_array = my_split("What a nice day", ' ');
    cout << "It is working: " << endl;
    for (unsigned int i = 0; i < my_array->size(); i++) {
      cout << "'" << my_array[i] << "' " << endl;
    }
    delete[] my_array;
    cout << "It is not working: " << endl;
    my_array= my_split("What a nice day", 'X');
    delete[] my_array;
  }
  catch (const char* excp) {
    cout << "Exception: " << excp << endl;
  }
  return 0;
}
