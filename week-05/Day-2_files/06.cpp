#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string get_content(string file_name);

int main() {
  // Write a function that reads the content of a file and returns it as a string
  // It should take the filename as a string parameter
  cout <<  get_content("fifth-exercise.txt");
  return 0;
}


string get_content(string _file_name) {
  ifstream file;
  file.open(_file_name.c_str());
  string output;
  if (file.is_open()) {
    string line;
    while (file >> line) {
      output += line + "\n";
    }
    file.close();
    return output;
  } else {
    return "Could not open the file\n";
  }  
}
