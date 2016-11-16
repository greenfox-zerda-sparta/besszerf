/*
 * todo.cpp
 *
 *  Created on: 2016.11.16.
 *      Author: caruzzo74
 */
#include <string>
#include <sstream>
#include "todo.h"

Todo::Todo() {
  title = "";
  state = 0;
  description = "";
}

Todo::Todo(std::string title) {
  this->title = title;
  state = 0;
  description = "";
}

Todo::Todo(std::string title, std::string description) {
  this->title = title;
  state = 0;
  this->description = description;
}

Todo::Todo(std::string title, unsigned int state, std::string description) {
  this->title = title;
  this->state = state;
  this->description = description;
}

std::string Todo::print_todo() {
  std::string output = "{\n";
  output += "title: \"" + this->title + "\",\n";
  std::ostringstream ss;
  ss << this->state;
  std::string strState = ss.str();
  output += "state: \"" + strState + "\",\n";
  output += "description: \"" + this->description + "\",\n";
  output += "}\n";
  return output;
}
