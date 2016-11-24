#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <algorithm>
typedef unsigned int uint;

using namespace std;

class Car {
  private:
  public:
    string type;
    string color;
    string plate_num;
    Car();
};

Car::Car() {
  type = "";
  color = "";
  plate_num = "";
}

int size = 1000;

string get_plate(int* num_pool) {
  string platenum = "";
  for (int i = 0; i < 3; i++) {
    platenum += (rand() %26) + 65;
  }
  platenum += "-";
  int index = rand() %1000;
  int num = num_pool[index];
  int temp = num_pool[size -1];
  num_pool[size - 1] = index;
  index = temp;
  size--;
  stringstream input;
  if (num < 10) {
    input << 00;
  } else if (num < 100) {
    input << 0;
  }
  input << num;
  platenum += input.str();
  return platenum;
}
int main() {
  //Create a vector of string, for the following car types:
  //"Moszkvics", "Volga", "ZISZ", "Tatra", "Zbrojovka", "Hotchkiss", "DAF", "Warszawa", "Puli", "Balaton",
  //"Benz", "Marauder", "Zsiguli" , "IFA", "Fjord", "Trabant", "Wartburg", "Martini"
  //Create a vector of strings, for the following colors:
  //"Piros", "Narancssárga", "Zöld", "Kék", "Türkiz", "Barna", "Lila", "Sárga", "Fekete", "Fehér"
  //Create a Car class, which holds 3 strings, the name of a car, the color of it, and the platenumber in a format like "AAA"-"000"
  //Create a 3 dimensional vector of our car class, that will represent a "parking house"
    //1 dimension: row of cars
    //2 dimension: cars on a platform like a table game
    //3 dimension: "parking house"
  //Make this parking house 4*4*8 (4*4 platform on 8 floors), then fill it with cars! :)
  //Give these cars a random type from our car type vector!
  //Give these cars a random color from our color vector!
  //Give these cars a random plate number!
  //Make sure there are no duplicates in car plates!
  //Print out how much "Sárga"-"Zsiguli" we have, with their position and platenumber in the parking house!
  //At the end empty the parking house!

  srand(time(NULL));
  int* num_pool = new int[1000];
  for (int i = 0; i < 1000; i++) {
    num_pool[i] = i;
  }
  for (int i = 0; i < 1000; i++) {
      int r = rand() % 1000;
      int temp = num_pool[i];
      num_pool[i] = num_pool[r];
      num_pool[r] = temp;
  }

  vector<string> types(18);
  types = {"Moszkvics", "Volga", "ZISZ", "Tatra", "Zbrojovka", "Hotchkiss", "DAF", "Warszawa", "Puli", "Balaton", "Benz", "Marauder", "Zsiguli" , "IFA", "Fjord", "Trabant", "Wartburg", "Martini"};
  vector<string> colors(10);
  colors = {"Piros", "Narancssárga", "Zöld", "Kék", "Türkiz", "Barna", "Lila", "Sárga", "Fekete", "Fehér"};

  srand(time(NULL));
  int cars_in_row = 4;
  int rows_in_floor = 4;
  int floors_in_building = 8;

  typedef vector<Car*> rows;
  typedef vector<rows> floors;
  typedef vector<floors> building;

  building parking_house(floors_in_building, floors(rows_in_floor, rows(cars_in_row)));
//  vector<vector<vector<Car*> > > parking_house(8, vector<vector<Car*> >(4, vector<Car*>(4)));
  for (int i = 0; i < floors_in_building; i++) {
    for (int j = 0; j < rows_in_floor; j++) {
      for (int k = 0; k < cars_in_row; k++) {
        parking_house[i][j][k] = new Car;
        parking_house[i][j][k]->type = types[rand() %18];
        parking_house[i][j][k]->color = colors[rand() %10];
        parking_house[i][j][k]->plate_num = get_plate(num_pool);
      }
    }
  }
  cout << "Sárga Zsiguli:" << endl;
  for (int i = 0; i < floors_in_building; i++) {
    for (int j = 0; j < rows_in_floor; j++) {
      for (int k = 0; k < cars_in_row; k++) {
        if (parking_house[i][j][k]->type == "Zsiguli" && parking_house[i][j][k]->color == "Sárga") {
          cout << " Plate number: " << parking_house[i][j][k]->plate_num << "\tFloor: " << i + 1 << " Row: " << j + 1 << " Spot: " << k + 1 << endl;
          parking_house[i][j][k];
        }
      }
    }
  }
  return 0;
}
