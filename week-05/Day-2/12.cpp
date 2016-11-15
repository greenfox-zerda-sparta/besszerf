#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void read_input(string file_name);
void print_decrypted(string line);
bool is_open = true;

int main() {
  // Create a program that decrypts the file called "reversed-order.txt",
  // and pritns the decrypred text to the terminal window.
  read_input("encrypted.txt");
  if (!is_open) {
    cerr << "Could not open file";
    return 1;
  }
  return 0;
}

void print_decrypted(string line) {
  for (int i = 0; i < line.length(); i++) {
    if ( line[i] < 123 && line[i] > 97) {
      cout << char (line[i] - 1);
    } else {
      switch (line[i]) {
        case 'a':
          cout << 'z';
          break;
        case 'A':
          cout << 'Z';
          break;
        default:
          cout << line[i];
      }
    }
  }
  cout << endl;
}

void read_input(string file_name) {
  ifstream file;
  file.open(file_name.c_str());
  if (file.is_open()) {
    is_open = true;
    string line;
    while (getline(file, line)) {
      print_decrypted(line);
    }
  }
  file.close();
}
