/*
 * stringmanipulation.h
 *
 *  Created on: 2016.11.16.
 *      Author: caruzzo74
 */

#ifndef STRINGMANIPULATION_H_
#define STRINGMANIPULATION_H_
#include <iostream>
#include <vector>
#include <string>

class StringManip {
  private:
    std::string origin;
    std::string beginning;
    std::string ending;
  public:
    StringManip(std::string orig, std::string beginning, std::string ending);
    void set_origin(std::string orig);
    void set_beginning(std::string beginning);
    void set_ending(std::string ending);
    void get_vector(std::vector<std::string>& return_vector);
    std::string get_substring();
};



#endif /* STRINGMANIPULATION_H_ */
