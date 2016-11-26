/*
 * parkinghouse.h
 *
 *  Created on: 2016.11.26.
 *      Author: caruzzo74
 */

#ifndef PARKINGHOUSE_H_
#define PARKINGHOUSE_H_
#include <vector>
#include "car.h"

typedef std::vector<Car*> rows;
typedef std::vector<rows> floors;
typedef std::vector<floors> building;

class ParkingHouse {
  private:
    const int CARS_IN_ROW;
    const int ROWS_IN_FLOOR;
    const int FLOORS_IN_BUILDING;
    building parking_house;
  public:
    ParkingHouse();
    ~ParkingHouse();
    void print_car(std::string color, std::string type);
};

#endif /* PARKINGHOUSE_H_ */
