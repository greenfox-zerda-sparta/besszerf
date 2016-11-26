#ifndef CAR_H_
#define CAR_H_
#include <string>
#include <vector>
#include "util.h"

class Car {
  private:
    std::string type;
    std::string color;
    std::string plate_num;
    static std::vector<std::string> used_plates;
    std::string get_new_plate();
    bool is_used(std::string platenum);
  public:
    std::string get_type();
    std::string get_color();
    std::string get_platenum();
    Car();
};

#endif /* CAR_H_ */
