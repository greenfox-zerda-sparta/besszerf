/*
 * todohandler.h
 *
 *  Created on: 2016.11.16.
 *      Author: caruzzo74
 */

#ifndef TODOHANDLER_H_
#define TODOHANDLER_H_
#include <string>
#include <vector>
#include "todo.h"

const std::string TODO_FILE = "todos.txt";

class TodoHandler {
  private:
    const std::string CONSERVING_BEGINNING_TAG_TO_OBJECT = "{\n";
    const std::string CONSERVING_CLOSING_TAG_TO_OBJECT = "}\n";
    std::vector<Todo*> todos;
    std::vector<std::string> todos_in_string;
  public:
    TodoHandler();
    TodoHandler(std::string title);
    TodoHandler(std::string title, std::string description);
    ~TodoHandler();
    unsigned int get_count_of_todos();
    void print_usage() const;
    void add_todo(Todo* todo);
    void add_todo(std::string title);
    void remove_todo(unsigned int index);
    void complete_todo(unsigned int index);
    void list_tasks();
};

#endif /* TODOHANDLER_H_ */
