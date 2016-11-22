#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_
#include <string> 

class FileHandler {
  private:
    std::string file_name;
  public:
    FileHandler(std::string file_name);
//    ~FileHandler();
    std::string read_file();
    void print_to_file(std::string content);
};

#endif /* FILEHANDLER_H_ */
