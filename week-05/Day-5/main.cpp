#include <iostream>
#include <string>
#include "todo.h"
#include "todohandler.h"

using namespace std;

int main(int argc, char* argv[]) {

  TodoHandler my_app;

  if (argc == 1) {
    my_app.print_usage(argv);
    return 1;
  }
  string arg1 = (string)argv[1];
  if (arg1 == "-l") {
    my_app.list_tasks();
    return 0;
  }
  if (arg1 == "-lf") {
        my_app.full_list();
        return 0;
  }
  if (arg1 == "-a") {
    if (my_app.add_todo(argc, argv)) {
      return 0;
    }
    return 1;
  }
  if (arg1 == "-c") {
    if (my_app.complete_todo(argc, argv)) {
      return 0;
    }
    return 1;
  }
  if (arg1 == "-p") {
    if (my_app.change_state_to_planned(argc, argv)) {
      return 0;
    }
    return 1;
  }
  if (arg1 == "-o") {
    if (my_app.change_state_to_ongoing(argc, argv)) {
      return 0;
    }
    return 1;
  }
  if (arg1 == "-r") {
    if (my_app.remove_todo(argc, argv)) {
      return 0;
    }
    return 1;
  }
  if (arg1 == "-d") {
    if (my_app.set_description(argc, argv)) {
      return 0;
    }
    return 1;
  }
  cerr << "Unsupported argument\n";
  my_app.print_usage(argv);
  return 1;
}

