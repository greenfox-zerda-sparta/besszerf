#include <iostream>
#include <fstream>
#include <string>
#include "todo.h"
#include "todohandler.h"

using namespace std;

const std::string TODO_FILE = "todos.txt";

int main(int argc, char* argv[]) {
  /*

   * Basics (mandatory):
      Prints usage
      Add new tasks
      Complete tasks
      Remove tasks
      List tasks

 * Advanced (optional):
    Refactor the application to align with the proposed architecture
    Write unittests for any unit it feels possible
   */
  TodoHandler my_app;
  if (argc == 1) {
    my_app.print_usage();
    return 1;
  }
  Todo my_todo("Feed the dog", 1, "On Saturday feed the fuckin' dog of my mother.");
  cout << my_todo.print_todo();
  return 0;
}

