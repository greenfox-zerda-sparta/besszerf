#include <iostream>
#include <string>
using namespace std;

// Write a function that receives a string and an unsigned integer.
// The function should return an array of strings, with two string in it.
// The first string should be the first part of the original string
// Characters in range [0,index-1].
// The second part should be the rest of the string characters range [index,length-1]
// Example: split("Rebarbara", 2)
// Result: {"Re", "barbara"}
// If the index is out of bounds, throw an exception.
//
// In the main function demonstrate the function when working, and when throwing an exception.
// Write the results to the console.


string* my_split(string word_to_split, unsigned int index) throw (const char*) {
  if (index > word_to_split.length()) {
    throw "Error: the given index is out of bounds.";
  }
  string* array = new string[2];
  for (unsigned int i = 0; i < index; i++) {
   array[0] += word_to_split[i];
  }
  for (unsigned int i = index; i < word_to_split.length(); i++) {
   array[1] += word_to_split[i];
  }
  return array;
}

int main() {
  try {
    string* my_array = my_split("Rebarbara", 2);
    cout << "It is working: " << my_array[0] << " and " << my_array[1] << endl;
    delete[] my_array;
    my_array= my_split("Rebarbara", 20);
    cout << "It is not working: " << my_array[1] << endl;
    delete[] my_array;
  }
  catch (const char* excp) {
    cout << "Exception: " << excp << endl;
  }
  return 0;
}
