#include <iostream>
#include <string>
#include <sstream>
#include "parkinghouse.h"

ParkingHouse::ParkingHouse() :
  CARS_IN_ROW(4),
  ROWS_IN_FLOOR(4),
  FLOORS_IN_BUILDING(8)
{
  parking_house = building(FLOORS_IN_BUILDING, floors(ROWS_IN_FLOOR, rows(CARS_IN_ROW)));
  for (int i = 0; i < FLOORS_IN_BUILDING; i++) {
    for (int j = 0; j < ROWS_IN_FLOOR; j++) {
      for (int k = 0; k < CARS_IN_ROW; k++) {
        parking_house[i][j][k] = new Car();
      }
    }
  }
}

ParkingHouse::~ParkingHouse() {
  for (int i = 0; i < FLOORS_IN_BUILDING; i++) {
    for (int j = 0; j < ROWS_IN_FLOOR; j++) {
      for (int k = 0; k < CARS_IN_ROW; k++) {
        delete parking_house[i][j][k];
      }
    }
  }
}

void ParkingHouse::print_car(std::string color, std::string type) {
  std::cout << color << " " << type << ":" << std::endl;
  int counter = 0;
  for (int i = 0; i < FLOORS_IN_BUILDING; i++) {
    for (int j = 0; j < ROWS_IN_FLOOR; j++) {
      for (int k = 0; k < CARS_IN_ROW; k++) {
        if (parking_house[i][j][k]->get_type() == type && parking_house[i][j][k]->get_color() == color) {
          counter++;
          std::cout << counter << ".\t"<< parking_house[i][j][k]->get_color() << " ";
          std::cout << parking_house[i][j][k]->get_type() << " (";
          std::cout << "Plate number: " << parking_house[i][j][k]->get_platenum() << "; Floor/Row/Spot: ";
          std::cout << i + 1 << "/" << j + 1 << "/" << k + 1 << ")"<< std::endl;
        }
      }
    }
  }
}

