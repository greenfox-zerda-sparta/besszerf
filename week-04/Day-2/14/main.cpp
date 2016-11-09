#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include "character.h"

using namespace std;

vector<int> random_numbers;
int random_selector = 0;

bool get_a_random(vector<int> &random_numbers) {
  random_selector += rand();
  random_shuffle ( random_numbers.begin(), random_numbers.end() );
  return random_numbers[random_selector % 10];
}


int main() {
  srand(time(NULL));
  int bools[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
  for (int i = 0; i < 10; i++){
      random_numbers.push_back(bools[i]);
  }
//RPG Game lite
      //Create a Character class with the following preferences:
      //name
      //character type (player/monster)
      //health point value
      //attack value
      //defense value
      //attacking method which takes a character class and decreases its health
      //value with (current character class attack - input character class defense),
      //if the output is minus, then our health is decreased
      //set the attacking method to have 50% chanse to count our attack value twice,
      //(2xcurrent attack - input defense) before calculating the final health points.

      //create 2 instances of the character class and fill their base stats from their constructor
      //make them attack each other with the attack method from the character class
      //after each round print both the attacker, and the attacked character health
      //make them fight each other until one of them has a health point lower or equal 0
      //print the winner and offer a new game

      //dont forget to use private variables, and get/set methods, and also place out_of_range
      //character class into a seperate file  return 0;
  Character kingArthur("Arthur", 100, 30, 20);
  Character bloodBunny("Dragon", 100, 30, 20, 1);
  bool attacker = 0;

  while (kingArthur.get_health_points() > 0 && bloodBunny .get_health_points() > 0) {
    kingArthur.print_character();
    bloodBunny.print_character();
    if (attacker) {
      bloodBunny.attack(kingArthur);
    } else {
      kingArthur.attack(bloodBunny);
    }
    attacker = get_a_random(random_numbers);
  }
  kingArthur.print_character();
  bloodBunny.print_character();
  cout << "Game over! ";
  if (kingArthur.get_health_points() > 0) {
    cout << kingArthur.get_name();
  } else {
    cout << bloodBunny.get_name();
  }
  cout << " win." << endl;
}
