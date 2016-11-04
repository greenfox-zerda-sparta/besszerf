#include <string>
#include <iostream>

using namespace std;

struct Pirate {
  string name;
  bool has_wooden_leg;
  short int gold_count;
};

int sum_of_golds(const Pirate* pirate, int len) {
  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum += pirate[i].gold_count;
  }
  return sum;
}

float average_of_golds(const Pirate* pirate, int len) {
  float sum = 0;
  for (int i = 0; i < len; i++) {
    sum += pirate[i].gold_count;
  }
  return sum/len;
}

string richest_one_of_wooden_legged(const Pirate* pirate, int len) {
  Pirate richest = {"", false, 0};
  for (int i = 0; i < len; i++) {
    if (pirate[i].has_wooden_leg && pirate[i].gold_count > richest.gold_count) {
      richest = pirate[i];
     }
  }
  return richest.name;
}
// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates

// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate

// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg

int main() {
  Pirate pirates[] = {
    {"Jack", false, 18},
    {"Uwe", true, 8},
    {"Hook", true, 12},
    {"Halloween kid", false, 0},
    {"Sea Wolf", true, 14},
    {"Morgan", false, 1}
  };
  cout << sum_of_golds(pirates, 6) << endl;
  cout << average_of_golds(pirates, 6) << endl;
  cout << richest_one_of_wooden_legged(pirates, 6) << endl;
  return 0;
}