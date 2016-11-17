#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atoi */
#include "todo.h"
#include "todohandler.h"

using namespace std;

bool is_a_number(string word) {
  bool result = true;
  for (unsigned int i = 0; i < word.length(); i++) {
    if (word[i] < 47 || word[i] > 57) {
      result = false;
      break;
    }
  }
  return result;
}

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
  } else if (argc == 2) {
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
      cerr << "Unable to add: No task is provided\n";
      return 1;
    }
    if (arg1 == "-r") {
      cerr << "Unable to remove: No index is provided\n";
      return 1;
    }
    if (arg1 == "-c") {
      cerr << "Unable to check: No index is provided\n";
      return 1;
    }
    cerr << "Unsupported argument\n";
    return 1;
  } else if (argc == 3) {
    string arg1 = (string)argv[1];
    string arg2 = (string)argv[2];
    if (arg1 == "-r") {
      if (!is_a_number(arg2)) {
        cerr << "Unable to remove: Index is not a number\n";
        return 1;
      }
      unsigned int a2 = (unsigned int)atoi(arg2.c_str());
      if (a2 > my_app.get_count_of_todos() || a2 < 1) {
        cerr << "Unable to remove: Index is out of bound\n";
         return 1;
      }
      my_app.remove_todo(a2);
    } else if (arg1 == "-c") {
      if (!is_a_number(arg2)) {
        cerr << "Unable to check: Index is not a number\n";
        return 1;
      }
      unsigned int a2 = (unsigned int)atoi(arg2.c_str());
      if (a2 > my_app.get_count_of_todos() || a2 < 1) {
        cerr << "Unable to check: Index is out of bound\n";
        return 1;
      }
      my_app.complete_todo(a2);
      return 0;
    } else if (arg1 == "-a") {
      my_app.add_todo(arg2);
    } else if (arg1 == "-o") {
      if (!is_a_number(arg2)) {
        cerr << "Unable to change state to 'ongoing': Index is not a number\n";
        return 1;
      }
      unsigned int a2 = (unsigned int)atoi(arg2.c_str());
      if (a2 > my_app.get_count_of_todos() || a2 < 1) {
        cerr << "Unable to change state to 'ongoing': Index is out of bound\n";
        return 1;
      }
      my_app.change_state_to_ongoing(a2);
      return 0;
    } else if (arg1 == "-p") {
      if (!is_a_number(arg2)) {
        cerr << "Unable to change state to 'planned': Index is not a number\n";
        return 1;
      }
      unsigned int a2 = (unsigned int)atoi(arg2.c_str());
      if (a2 > my_app.get_count_of_todos() || a2 < 1) {
        cerr << "Unable to change state to 'planned': Index is out of bound\n";
        return 1;
      }
      my_app.change_state_to_planned(a2);
      return 0;
    } else if (arg1 == "-a") {
      my_app.add_todo(arg2);
      return 0;
    } else {
      cerr << "Unsupported argument\n";
      return 1;
    }
  } else if(argc == 4) {
    string arg1 = (string)argv[1];
    string arg2 = (string)argv[2];
    string arg3 = (string)argv[3];
    if (arg1 == "-d") {
      if (!is_a_number(arg2)) {
        cerr << "Unable to set description: Index is not a number\n";
        return 1;
      }
      unsigned int a2 = (unsigned int)atoi(arg2.c_str());
      if (a2 > my_app.get_count_of_todos() || a2 < 1) {
        cerr << "Unable to set description: Index is out of bound\n";
        return 1;
      }
      my_app.set_description(a2, arg3);
      return 0;
      }
      cerr << "Invalid arguments\n";
      return 1;
  } else {
    cerr << "Too many arguments\n";
    return 1;
  }
  return 0;
}

