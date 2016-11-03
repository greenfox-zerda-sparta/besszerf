#include <string>
#include <iostream>

using namespace std;

struct House {
  string address;
  float price;
  short int rooms;
  int area;
};

const int market_price = 400;

bool is_worth_to_buy(const House &house) {
  bool result = false;
  if (house.price < market_price * house.area) result = true;
  return result;
}

int sum__of_houses_is_worth_to_buy(const House* house, int len) {
  int sum = 0;
  for (int i = 0; i < len; i++) {
    if (is_worth_to_buy(house[i])) sum += 1;
  }
  return sum;
}

void print_house(const House &house) {
  cout << house.address << " " << house.price << " " << house.rooms << " " << house.area << "\n";
}

void print_all_houses(const House *houses, int len) {
  for (int i = 0; i < len; i++) {
    print_house(houses[i]);
  }
}

// Create a function that takes an array of houses (and it's length),
// then it creates a new array that consists new houses with the calculated price,
// but all the other properties are the same.

House* reprice_houses(House* houses, int len) {
  House *houses_with_new_prices = new House[len];
  for (int i = 0; i < len; i++) {
    houses_with_new_prices[i].address = houses[i].address;
    houses_with_new_prices[i].price = houses[i].area * market_price;
    houses_with_new_prices[i].rooms = houses[i].rooms;
    houses_with_new_prices[i].area = houses[i].area;
  }
  return houses_with_new_prices;
}

// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
//
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a refrence to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)
//
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
//
// Create a function that takes an array of houses (and it's length),
// then it creates a new array that consists new houses with the calculated price,
// but all the other properties are the same.

int main() {
  House houses[] = {
    {"Bp", 11500, 1, 30},
    {"Berlin", 200000, 8, 500},
    {"Tokyo", 28000, 2, 65},
    {"Bukarest", 12000, 3, 45},
    {"Kukutyin", 10000, 5, 250},
    {"House of Jesus in Heaven", 0, 15000, 1500000}
  };

  House* repriced_houses = new House[6];
  repriced_houses = reprice_houses(houses, 6);
  cout << sum__of_houses_is_worth_to_buy(houses, 6) << endl;
  print_all_houses(repriced_houses, 6);
  delete[] repriced_houses;
  return 0;
}
