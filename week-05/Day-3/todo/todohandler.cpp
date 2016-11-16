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

using namespace std;

TodoHandler::TodoHandler() {
  todos = NULL;
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
