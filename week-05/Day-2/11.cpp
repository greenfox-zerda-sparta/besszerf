#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> out_v;
void get_output(string file_name);

int main() {
  // Create a program that decrypts the file called "reversed-order.txt",
  // and pritns the decrypred text to the terminal window.
  get_output("reversed-order.txt");
  if (out_v.size() == 0) {
    cerr << "Could not open file";
    return 1;
  } else {
    for (int i = out_v.size()-1; i > -1; i-- ) {
      cout << out_v[i] << endl;
    }
    cout << endl;
  }
  return 0;
}

void get_output(string file_name) {
  ifstream file;
  file.open(file_name.c_str());
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      out_v.push_back(line);
    }
  }
  file.close();
}
