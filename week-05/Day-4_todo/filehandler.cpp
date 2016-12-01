/*
 * filehandler.cpp
 *
 *  Created on: 2016.11.16.
 *      Author: caruzzo74
 */
#include <fstream>
#include <string>
#include "filehandler.h"

using namespace std;

FileHandler::FileHandler(string file_name) {
  this->file_name = file_name;
}


string FileHandler::read_file() {
  ifstream file;
  file.open(this->file_name.c_str());
  string output;
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      output += line + "\n";
    }
    file.close();
    return output;
  } else {
    return "Could not open the file.";
  }
}

void FileHandler::print_to_file(string content) {
  ofstream file;
  file.open(this->file_name.c_str());
  file << content;
  file.close();
}


