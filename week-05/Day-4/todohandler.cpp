/*
 * todohandler.cpp
 *
 *  Created on: 2016.11.16.
 *      Author: caruzzo74
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "todohandler.h"
#include "filehandler.h"
#include "stringmanipulation.h"

using namespace std;

TodoHandler::TodoHandler() {
  FileHandler file_handler(TODO_FILE);
  string file_content = file_handler.read_file();
  StringManip string_todos(file_content, CONSERVING_BEGINNING_TAG_TO_OBJECT, CONSERVING_CLOSING_TAG_TO_OBJECT);
  string_todos.get_vector(todos_in_string);
  if (todos_in_string.size() != 0) {
    for (unsigned int i = 0; i < todos_in_string.size(); i++) {
      Todo* just_awaked_todo = new Todo(todos_in_string[i]);
      add_todo(just_awaked_todo);
    }
  }
}

void TodoHandler::print_usage() const {
  cout << "\nCLI Todo application\n";
  cout << "==================== \n\n";
  cout << "Command line arguments:\n";
  cout << " -l   Lists all the tasks\n";
  cout << " -a   Adds a new task\n";
  cout << " -r   Removes a task\n";
  cout << " -c   Completes a task\n\n";
}

TodoHandler::~TodoHandler() {
  std::string content;
  for (unsigned int i = 0; i < todos.size(); i++) {
    content += CONSERVING_BEGINNING_TAG_TO_OBJECT;
    content += todos[i]->go_to_sleep_todo();
    content += CONSERVING_CLOSING_TAG_TO_OBJECT;
  }
  FileHandler file_handler(TODO_FILE);
  file_handler.print_to_file(content);
  for (unsigned int i = 0; i < todos.size(); i++) {
    delete todos[i];
    todos.erase(todos.begin() + i);
  }
}

void TodoHandler::add_todo(Todo* todo) {
  if (todo != 0) {
    todos.push_back(todo);
  }
}

void TodoHandler::add_todo(string title) {
  Todo *new_todo = new Todo;
  new_todo->set_title(title);
  new_todo->set_state("1");
  todos.push_back(new_todo);
  std::cout << "New todo is added. \n";
}

unsigned int TodoHandler::get_count_of_todos() {
  return todos.size();
}

void TodoHandler::list_tasks() {
  for (unsigned int i = 0; i < todos.size(); i++) {
    cout << i +1  << " ";
    todos[i]->print_todo();
  }
}

void TodoHandler::remove_todo(unsigned int index) {
  delete todos[index - 1];
  todos.erase(todos.begin() + index - 1);
  std::cout << "Todo " << index << " is removed. \n";
}

void TodoHandler::complete_todo(unsigned int index) {
  todos[index - 1]->set_state("3");
  std::cout << "State of todo " << index <<" is changed to 'completed'. \n";
}

