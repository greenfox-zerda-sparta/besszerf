#ifndef TEXTHANDLER_H_
#define TEXTHANDLER_H_
#include <iostream>
#include <vector>
#include <string>

class TextHandler {
  private:
    std::string origin;
    std::string beginning;
    std::string ending;
  public:
    TextHandler();
    TextHandler(std::string orig, std::string beginning, std::string ending);
    void set_origin(std::string orig);
    void set_beginning(std::string beginning);
    void set_ending(std::string ending);
    void get_vector(std::vector<std::string>& return_vector);
    std::string get_substring();
    bool is_a_number(std::string str);
};

#endif /* TEXTHANDLER_H_ */
