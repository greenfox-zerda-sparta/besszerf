#include <iostream>
#include <string>
#include "todo.h"
#include "todohandler.h"

using namespace std;

int main(int argc, char* argv[]) {

  TodoHandler my_app;

  if (argc == 1) return my_app.print_usage(argv);
  string arg1 = (string)argv[1];
  if (arg1 == "-l") return my_app.list_tasks();
  if (arg1 == "-lf") return my_app.full_list();
  if (arg1 == "-a") return my_app.add_todo(argc, argv);
  if (arg1 == "-c") return my_app.complete_todo(argc, argv);
  if (arg1 == "-p") return my_app.change_state_to_planned(argc, argv);
  if (arg1 == "-o") return my_app.change_state_to_ongoing(argc, argv);
  if (arg1 == "-r") return my_app.remove_todo(argc, argv);
  if (arg1 == "-d") return my_app.set_description(argc, argv);
  cerr << "Unsupported argument: " << argv[1] << "\n";
  my_app.print_usage(argv);
  return 1;
}
