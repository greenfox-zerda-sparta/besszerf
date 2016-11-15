#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Write a program that prints a content of a file called "fifth-exercise.txt"
  // If it could not open the file it should write: "Could not open the file" to the standard error
  // The program should return 2 if there where an error
  ifstream file;
  string content;
  file.open("fifth-exercise.txt");
  if (file.is_open()) {
    while (file >> content) {
      cout << content << endl;
    }
    file.close();
  } else {
    cerr << "Could not open the file" << endl;
    return 2;
  }
  return 0;
}
