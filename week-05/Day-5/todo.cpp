#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* atoi */
#include "todo.h"

Todo::Todo() {
  title = "";
  state = 0;
  description = "";
}

Todo::Todo(std::string sleeping_todo) {
  TextHandler string_todo(sleeping_todo + "\n", CONSERVING_BEGINNING_TAG_TO_TITLE, CONSERVING_CLOSING_TAG_TO_ALL);
  this->title = string_todo.get_substring();
  string_todo.set_beginning(CONSERVING_BEGINNING_TAG_TO_STATE);
  std::string str_state = string_todo.get_substring();
  this->state = atoi(str_state.c_str());
  std::string _description;
  string_todo.set_beginning(CONSERVING_BEGINNING_TAG_TO_DESCRIPTION);
  this->description = string_todo.get_substring();
}

std::string Todo::go_to_sleep_todo() {
  std::string output;
  output += CONSERVING_BEGINNING_TAG_TO_TITLE + this->title + CONSERVING_CLOSING_TAG_TO_ALL;
  std::ostringstream ss;
  ss << this->state;
  std::string strState = ss.str();
  output += CONSERVING_BEGINNING_TAG_TO_STATE + strState + CONSERVING_CLOSING_TAG_TO_ALL;
  output += CONSERVING_BEGINNING_TAG_TO_DESCRIPTION + this->description + CONSERVING_CLOSING_TAG_TO_ALL;
  return output;
}

void Todo::print_todo() {
  std::string bracket;
  if (this->state == 0) bracket = "[   ] ";
  if (this->state == 1) bracket = "[ P ] ";
  if (this->state == 2) bracket = "[ O ] ";
  if (this->state == 3) bracket = "[ X ] ";
  std::cout << bracket << this->title << std::endl;
}

void Todo::full_print_todo() {
  std::string bracket;
  if (this->state == 0) bracket = "* Initialised";
  if (this->state == 1) bracket = "* Planned";
  if (this->state == 2) bracket = "* Ongoing";
  if (this->state == 3) bracket = "* Completed";
  std::cout << "    " << this->title << "\n" << "    "<< bracket << "\n" << "    " << this->description << std::endl;
}

void Todo::set_title(std::string title) {
  this->title = title;
}
void Todo::set_state(std::string str_state) {
  this->state = atoi(str_state.c_str());
}
void Todo::set_description(std::string description) {
  this->description = description;
}
