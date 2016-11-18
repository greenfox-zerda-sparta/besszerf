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
    void print_usage(char** arg) const;
    void add_todo(Todo* todo);
    bool add_todo(int argc, char** arg);
    bool remove_todo(int argc, char** arg);
    bool complete_todo(int argc, char** arg);
    bool change_state_to_ongoing(int argc, char** arg);
    bool change_state_to_planned(int argc, char** arg);
    void list_tasks();
    void full_list();
    bool set_description(int argc, char** arg);
};

#endif /* TODOHANDLER_H_ */
