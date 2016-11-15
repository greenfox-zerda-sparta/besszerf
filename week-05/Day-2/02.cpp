#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open a file called "second-exercise.txt"
    // Read the content of the file and print it to the terminal window

    ifstream my_file;
    my_file.open("second-exercise.txt");
    string content;
    my_file >> content;
    cout << content << endl;
    return 0;
}
