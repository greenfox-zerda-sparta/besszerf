#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string opening_error = "Could not open file";

string read_file(string file_name);
void print_to_file(string file_name, string content);
int cp(string file1, string file2);

int main() {
  // Write a function that copies a file to an other
  // It should take the filenames as parameters
  // It should return a boolean that shows if the copy was successful
  string file1 = "sample.txt";
  string file2 = "output.txt";
  return cp(file1, file2);
}

string read_file(string file_name) {
  ifstream file;
  file.open(file_name.c_str());
  string output;
  if (file.is_open()) {
    string line;
    while (file >> line) {
      output += line + "\n";
    }
    file.close();
    return output;
  } else {
    return opening_error;
  }
}

void print_to_file(string file_name, string content) {
  ofstream file;
  file.open(file_name.c_str());
  file << content;
  file.close();
}

int cp(string file1, string file2) {
  string content;
  content = read_file(file1);
  if (content == opening_error) {
    cerr << opening_error << endl;
    return 1;
  } else {
    print_to_file(file2, content);
    return 0;
  }
}
