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
    int print_usage(char** arg) const;
    void add_todo(Todo* todo);
    int add_todo(int argc, char** arg);
    int remove_todo(int argc, char** arg);
    int complete_todo(int argc, char** arg);
    int change_state_to_ongoing(int argc, char** arg);
    int change_state_to_planned(int argc, char** arg);
    int list_tasks();
    int full_list();
    int set_description(int argc, char** arg);
};

#endif /* TODOHANDLER_H_ */
