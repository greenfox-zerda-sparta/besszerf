/*
 * todohandler.h
 *
 *  Created on: 2016.11.16.
 *      Author: caruzzo74
 */

#ifndef TODOHANDLER_H_
#define TODOHANDLER_H_
#include <string>
#include "todo.h"

class TodoHandler {
  private:
    Todo* todos;
  public:
    TodoHandler();
    TodoHandler(std::string title);
    TodoHandler(std::string title, std::string deadline);
    void print_usage() const;
    void add_todo(Todo todo);
    void complete_todo(Todo todo);
};

#endif /* TODOHANDLER_H_ */
