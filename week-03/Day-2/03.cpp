#include <string>
#include <iostream>

using namespace std;

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  CarType type;
  double km;
  double gas;
};

Car construct_car(Car &name, CarType type = VOLVO, double km = 0, double gas = 50) {
  name.type = type;
  name.km = km;
  name.gas = gas;
  return name;
}

void print_car(Car inst) {
  cout << inst.type << endl;
  cout << inst.km << endl;
  (inst.type != TESLA) && cout << inst.gas << endl;
}


// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {
  Car my_car, your_car, Jesus_car;
  construct_car(my_car, VOLVO, 500, 80);
  construct_car(Jesus_car, TESLA);

  print_car(my_car);
  print_car(Jesus_car);
  return 0;
}

/* Second version with pointers*/

#include <string>
#include <iostream>

using namespace std;

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  CarType type;
  double km;
  double gas;
};

void construct_car(Car* car, CarType type = VOLVO, double km = 0, double gas = 50) {
  car->type = type;
  car->km = km;
  car->gas = gas;
}

void print_car(const Car* inst) {
  cout << inst->type << endl;
  cout << inst->km << endl;
  (inst->type != TESLA) && cout << inst->gas << endl;
}


// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {
  Car *my_car = new Car;
  Car *Jesus_car = new Car;
  construct_car(my_car, VOLVO, 500, 80);
  construct_car(Jesus_car, TESLA);

  print_car(my_car);
  print_car(Jesus_car);

  delete my_car;
  delete Jesus_car;
  return 0;
}

