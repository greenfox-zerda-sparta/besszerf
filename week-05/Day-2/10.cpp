#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string opening_error = "Could not open file";
string result;

string get_output(string file_name);

int main() {
  // Create a program that decrypts the file called "reversed-lines.txt",
  // and pritns the decrypred text to the terminal window.
  string file_name = "reversed-lines.txt";
  string output = get_output(file_name);
  if (output == opening_error) {
    cerr << opening_error << endl;
    return 1;
  } else {
    cout << output;
  }

  return 0;
}

string get_output(string file_name) {
  ifstream file;
  file.open(file_name.c_str());
  string output;
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      int len = line.length();
      for (int i = len - 1; i > -1; i--) {
        output += line[i];
      }
      output += "\n";
    }
    file.close();
    return output;
  } else {
    return opening_error;
  }
}
