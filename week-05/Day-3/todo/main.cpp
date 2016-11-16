#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Todo {
  private:
    std::string title;
    unsigned int state; // 0 - initialized 1 -planned, 2 -ongoing, 3 - completed
    std::string deadline;
    std::string description;
  public:
    Todo();
    Todo(string title);
    Todo(string title, string deadline);
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

class TodoHandler {
  private:
    Todo* todos;
    const std::string TODO_FILE = "todos.txt";
  public:
    TodoHandler();
    TodoHandler(string title);
    TodoHandler(string title, string deadline);
    void print_usage() const; // to todoHandler
    void add_todo(Todo todo); // to todoHandler
    void complete_todo(Todo todo); // to todoHandler
};

Todo::Todo() {
  title = "";
  state = 0;
  deadline = "";
  description = "";
}

Todo::Todo(string title) {
  this->title = title;
  state = 0;
  deadline = "";
  description = "";
}

Todo::Todo(string title, string deadline) {
  this->title = title;
  state = 0;
  this->deadline = deadline;
  description = "";
}

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

int main(int argc, char* argv[]) {
  /*

   * Basics (mandatory):
      Prints usage
      A todo task has (at least) a completed state and a description
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
  }
  return 0;
}

