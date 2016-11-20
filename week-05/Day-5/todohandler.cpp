#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */
#include "todohandler.h"
#include "filehandler.h"
#include "texthandler.h"

using namespace std;

TodoHandler::TodoHandler() {
  FileHandler file_handler(TODO_FILE);
  string file_content = file_handler.read_file();
  TextHandler string_todos(file_content, CONSERVING_BEGINNING_TAG_TO_OBJECT, CONSERVING_CLOSING_TAG_TO_OBJECT);
  string_todos.get_vector(todos_in_string);
  if (todos_in_string.size() != 0) {
    for (unsigned int i = 0; i < todos_in_string.size(); i++) {
      Todo* just_awaked_todo = new Todo(todos_in_string[i]);
      add_todo(just_awaked_todo);
    }
  }
}

int TodoHandler::print_usage(char ** arg) const {
  cout << "\nCLI Todo application\n";
  cout << "==================== \n\n";
  cout << "Command line arguments:\n";
  cout << " -l   Lists all the tasks\n";
  cout << " -lf  Make a full list of all the tasks\n";
  cout << " -a   Adds a new task\n";
  cout << " -d   Sets description to task at given index.\n";
  cout << "         Should use: " << arg[0] << " -d index description.\n";
  cout << " -r   Removes a task\n";
  cout << " -o   Change state a task to 'ongoing'\n";
  cout << " -c   Completes a task\n";
  cout << " -p   Change state a task back to 'planned'\n\n";
  return 0;
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

int TodoHandler::add_todo(int argc, char** arg) {
  if (argc < 3) {
    cerr << "Unable to add: No task is provided\n";
    return 1;
  }
  string message = "New ";
  if (argc > 3) {
    message = "Adding more than 1 todo is not supported: Only the first ";
  }
  string arg2 = (string)arg[2];
  Todo *new_todo = new Todo;
  new_todo->set_title(arg2);
  new_todo->set_state("1");
  todos.push_back(new_todo);
  std::cout << message << "todo is added. \n";
  return 0;
}

unsigned int TodoHandler::get_count_of_todos() {
  return todos.size();
}

int TodoHandler::list_tasks() {
  for (unsigned int i = 0; i < todos.size(); i++) {
    cout << i +1  << " ";
    todos[i]->print_todo();
  }
  return 0;
}

int TodoHandler::full_list() {
  for (unsigned int i = 0; i < todos.size(); i++) {
    cout << i +1  << ". Todo\n";
    todos[i]->full_print_todo();
  }
  return 0;
}

int TodoHandler::remove_todo(int argc, char** arg) {
  if (argc < 3) {
    cerr << "Unable to remove: Index is not a number\n";
    return 1;
  }
  string message = "Todo ";
  if (argc > 3) {
  message = "Removing more than 1 todo is not supported: Only the first given todo ";
  }
  string arg2 = (string)arg[2];
  TextHandler clarg;
  if (!clarg.is_a_number(arg2)) {
    cerr << "Unable to remove: Index is not a number\n";
    return 1;
  }
  unsigned int a2 = (unsigned int)atoi(arg2.c_str());
cout << a2 << endl;
  if (a2 > get_count_of_todos() || a2 < 1) {
    cerr << "Unable to remove: Index is out of bound\n";
     return 1;
  }
  delete todos[a2 - 1];
  todos.erase(todos.begin() + a2 - 1);
  std::cout << message << a2 << " is removed. \n";
  return 0;
}

int TodoHandler::complete_todo(int argc, char** arg) {
  if (argc < 3) {
    cerr << "Unable to check: Index is not a number\n";
    return 1;
  }
  string message = "Todo ";
  if (argc > 3) {
  message = "Only 1 todo is supported: todo ";
  }
  string arg2 = (string)arg[2];
  TextHandler clarg;
  if (!clarg.is_a_number(arg2)) {
    cerr << "Unable to check: Index is not a number\n";
    return 1;
  }
  unsigned int a2 = (unsigned int)atoi(arg2.c_str());
  if (a2 > get_count_of_todos() || a2 < 1) {
    cerr << "Unable to check: Index is out of bound\n";
     return 1;
  }
  todos[a2 - 1]->set_state("3");
  std::cout << message << a2 << " state is changed to 'completed'. \n";
  return 0;
}

int TodoHandler::change_state_to_ongoing(int argc, char** arg) {
  if (argc < 3) {
    cerr << "Unable to change state: Index is not a number\n";
    return 1;
  }
  string message = "Todo ";
  if (argc > 3) {
  message = "Only 1 todo is supported: todo ";
  }
  string arg2 = (string)arg[2];
  TextHandler clarg;
  if (!clarg.is_a_number(arg2)) {
    cerr << "Unable to change state: Index is not a number\n";
    return 1;
  }
  unsigned int a2 = (unsigned int)atoi(arg2.c_str());
  if (a2 > get_count_of_todos() || a2 < 1) {
    cerr << "Unable to change state: Index is out of bound\n";
     return 1;
  }
  todos[a2 - 1]->set_state("2");
  std::cout << message << a2 << " state is changed to 'ongoing'. \n";
  return 0;
}

int TodoHandler::change_state_to_planned(int argc, char** arg) {
  if (argc < 3) {
    cerr << "Unable to change state: Index is not a number\n";
    return 1;
  }
  string message = "Todo ";
  if (argc > 3) {
  message = "Only 1 todo is supported: todo ";
  }
  string arg2 = (string)arg[2];
  TextHandler clarg;
  if (!clarg.is_a_number(arg2)) {
    cerr << "Unable to change state: Index is not a number\n";
    return 1;
  }
  unsigned int a2 = (unsigned int)atoi(arg2.c_str());
  if (a2 > get_count_of_todos() || a2 < 1) {
    cerr << "Unable to change state: Index is out of bound\n";
     return 1;
  }
  todos[a2 - 1]->set_state("1");
  std::cout << message << a2 << " state is changed back to 'planned'. \n";
  return 0;
}

int TodoHandler::set_description(int argc, char** arg) {
  if (argc < 4) {
    cerr << "Unable set description: Too few arguments.\n";
    cerr << "Usage: " << arg[0] << " -d index description\n";
    return 1;
  }
  string message = "Todo ";
  if (argc > 4) {
  cerr << "Too many arguments.\n";
  }
  string arg2 = (string)arg[2];
  string arg3 = (string)arg[3];
  TextHandler clarg;
  if (!clarg.is_a_number(arg2)) {
    cerr << "Unable to set description: Index is not a number\n";
    cerr << "Usage: " << arg[0] << " -d index description\n";
    return 1;
  }
  unsigned int a2 = (unsigned int)atoi(arg2.c_str());
  if (a2 > get_count_of_todos() || a2 < 1) {
    cerr << "Unable to set description: Index is out of bound\n";
     return 1;
  }
  todos[a2 - 1]->set_description(arg3);
  std::cout << "Description of todo " << a2 <<" is set to the given. \n";
  return 0;
}
