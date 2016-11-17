/*
 * todohandler.cpp
 *
 *  Created on: 2016.11.16.
 *      Author: caruzzo74
 */
#include <iostream>
#include <fstream>
#include <string>
#include "todohandler.h"
#include "filehandler.h"

using namespace std;

TodoHandler::TodoHandler() {
  todos = NULL;
  todo_count = 0;
  FileHandler file_handler(TODO_FILE);
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
  for (unsigned int i = 0; i < todo_count; i++) {
    content += todos[i]->print_todo();
  }
  FileHandler file_handler(TODO_FILE);
  file_handler.print_to_file(content);
}

void TodoHandler::add_todo(Todo* todo) {
  Todo** temp = new Todo*[todo_count + 1];
  if (todo != 0) {
    for (unsigned int i = 0; i < todo_count; i++) {
      temp[i] = todos[i];
    }
  }
  temp[todo_count] = todo;
  delete[] todos;
  todos = temp;
  todo_count++;
}
