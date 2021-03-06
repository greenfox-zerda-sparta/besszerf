#ifndef TODO_H_
#define TODO_H_
#include <string>

#include "texthandler.h"

//       A todo task has (at least) a completed state and a description

class Todo {
  private:
    std::string title;
    unsigned int state; // 0 - initialized 1 - planned, 2 - ongoing, 3 - completed
    std::string description;
    const std::string CONSERVING_BEGINNING_TAG_TO_TITLE = "title: \"";
    const std::string CONSERVING_BEGINNING_TAG_TO_STATE = "state: \"";
    const std::string CONSERVING_BEGINNING_TAG_TO_DESCRIPTION = "description: \"";
    const std::string CONSERVING_CLOSING_TAG_TO_ALL = "\",\n";
  public:
    Todo();
    Todo(std::string sleeping_todo);
    void print_todo();
    void full_print_todo();
    std::string go_to_sleep_todo();
    void set_title(std::string title);
    void set_state(std::string state);
    void set_description(std::string description);
};

#endif /* TODO_H_ */
