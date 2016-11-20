#include "texthandler.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

TextHandler::TextHandler() {
  this->origin = "";
  this->beginning = "";
  this->ending = "";
}

TextHandler::TextHandler(std::string origin, std::string beginning, std::string ending) {
  this->origin = origin;
  this->beginning = beginning;
  this->ending = ending;
}
string TextHandler::get_substring() {
  if (origin != "") {
    size_t beg_pos = origin.find(beginning);
    if (beg_pos == string::npos) {
      return "ERROR";
    }
    string new_content = origin.substr((int)beg_pos + beginning.length());
    origin = new_content;
    size_t end_pos = origin.find(ending);
    new_content = origin.substr(0, end_pos);
    origin = origin.substr(end_pos + ending.length());
    return new_content;
  }
  return "ERROR";
}


void TextHandler::get_vector(std::vector<std::string>& return_vector) {
  if (origin != "") {
    string one_result;
    do {
      one_result = get_substring();
      if (one_result == "ERROR") {
        return;
      }
      return_vector.push_back(one_result);
    } while (true);
  }
}

void TextHandler::set_origin(std::string origin) {
  this->origin = origin;
}

void TextHandler::set_beginning(std::string beginning) {
  this->beginning = beginning;
}

void TextHandler::set_ending(std::string ending) {
  this->ending = ending;
}

bool TextHandler::is_a_number(std::string str) {
  bool result = true;
  for (unsigned int i = 0; i < str.length(); i++) {
    if (str[i] < 47 || str[i] > 57) {
      result = false;
      break;
    }
  }
  return result;
}
