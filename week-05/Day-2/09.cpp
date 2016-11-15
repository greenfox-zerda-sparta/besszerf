#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string opening_error = "Could not open file";

string read_file(string file_name);
string decrypt_duplicated(string input);

int main() {
  // Create a program that decrypts the file called "duplicated-chars.txt",
  // and pritns the decrypred text to the terminal window.
  string file_name = "duplicated-chars.txt";
  string input = read_file(file_name);
  if (input == opening_error) {
    cerr << opening_error << endl;
    return 1;
  } else {
    cout << decrypt_duplicated(input);
  }
  return 0;
}

string decrypt_duplicated(string input) {
  string output;
  for (int i = 0; i < input.length(); i+=2) {
    output += input[i];
  }
  return output;
}

string read_file(string file_name) {
  ifstream file;
  file.open(file_name.c_str());
  string output;
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      output += line + "\n";
    }
    file.close();
    return output;
  } else {
    return opening_error;
  }
}
