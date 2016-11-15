#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print_to_file(string file_name, string content);

int main() {
  // Write a function that writes a string to a file
  // It should take the filename and the content as a string parameter

  print_to_file("sample.txt", "Jesus Christ!\n");

  return 0;
}

void print_to_file(string file_name, string content) {
  ofstream file;
  file.open(file_name.c_str());
  file << content;
  file.close();
}