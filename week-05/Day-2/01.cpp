#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // Open a file called "first-exercise.txt"
  // Write your name in it as a single line
  ofstream myfile;
  myfile.open("example.txt");
  myfile << "Ferenc Besszer";
  myfile.close();
  return 0;
}
