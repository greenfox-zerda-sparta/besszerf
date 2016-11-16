/*
 * todo.h
 *
 *  Created on: 2016.11.16.
 *      Author: caruzzo74
 */

#ifndef TODO_H_
#define TODO_H_
#include <string>

//       A todo task has (at least) a completed state and a description

class Todo {
  private:
    std::string title;
    unsigned int state; // 0 - initialized 1 - planned, 2 - ongoing, 3 - completed
    std::string description;
  public:
    Todo();
    Todo(std::string title);
    Todo(std::string title, std::string description);
    Todo(std::string title, unsigned int state, std::string description);
    std::string print_todo();
    //    ~Todo();
/*    bool set_title(Todo todo);
    bool set_state(Todo todo);
    bool set_deadline(Todo todo);
    bool set_description(Todo todo);
    std::string get_title();
    unsigned int get_state();
    std::string get_deadline();
    std::string get_description();
*/};

#endif /* TODO_H_ */
