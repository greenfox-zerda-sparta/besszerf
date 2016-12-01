#include <iostream>
#include "board.hpp"
#include "bubble.h"
using namespace std;

int board_height = 10;
int board_width = 10;
int number_of_bubbles = 10;
int move_units_max = 3;
int num_of_turns = 2;

int main() {
  //Bubble Game!!!!
  //Create a class template that has the values and methods to operate our bubble game!
  //Our bubble game has a fix 10*10 square map, where our newly generated bubbles move in constant direction
  //they move with predefined x-y coordinates, which they take in their constructor
  //If they "hit" the wall multiply the correct direction "vector" with -1
  //The game has 10 bubbles
  //the bubbles start from random x-y coordinates, and can move 0-3 unit maximum in each direction
  //You have to run the games for 10 rounds
  //In each round the bubble move from their spot to the next spot pointed with its direction vector
  //After 10 rounds print how many times did the balls collide, and how many times did they hit the wall

  Board<int> bubble_board;
  bubble_board.print_board();
  for (int i = 0; i < num_of_turns; i++) {
    bubble_board.next_turn();
  }
  cout << "During " << num_of_turns << " turns:" << endl;
      cout << "   Bubbles hit the wall: " << bubble_board.get_wall_hits() << " times."<< endl;
  cout << "   Collisions: " << bubble_board.get_collisions() << endl;
  return 0;
}
