#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "character.h"

using namespace std;

string in_words[] = {"player", "monster"};

Character::Character(string name, int health_points, int attacking_force, int defending_power, bool type) {
  this->name = name;
  this->type = type;
  this->health_points = health_points;
  this->attacking_force = attacking_force;
  this->defending_power = defending_power;
}

int Character::calculate_result_of_attack(Character& enemy) {
  int random = rand() % 2 + 1;
  int act_force = this->attacking_force * (random);
  int result = act_force - enemy.get_defending_power();
  return result;
}

void Character::attack(Character& enemy) {
  int result_of_attack = calculate_result_of_attack(enemy);
  if (result_of_attack < 0) {
    this->health_points += result_of_attack;
    if (this->health_points < 0) this->health_points = 0;
  } else {
    enemy.set_health_points (enemy.get_health_points() - result_of_attack);
  }    if (enemy.get_health_points() < 0) enemy.set_health_points(0);
  cout << this->name << " attacks...\n";

}
const string Character::get_name() {
  return this->name;
}

const int Character::get_health_points() {
  return this->health_points;
}

void Character::set_health_points(int points) {
  this->health_points = points;
}

const int Character::get_defending_power() {
  return this->defending_power;
}

const void Character::print_character() {
  cout << this->name << "; " << in_words[this->type] << " (Health: " << this->health_points << ", Attacking force: " <<
      this->attacking_force << ", " << " Defending power: " << this->defending_power << ")" << endl;
}
