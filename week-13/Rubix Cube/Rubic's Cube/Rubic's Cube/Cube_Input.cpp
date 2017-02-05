#include "Cube_Input.h"

Cube_Input::Cube_Input() {
  if (if_user_wants_input()) {
    has_input = true;
    get_input();
  }
  else {
    has_input = false;
  }
}

bool Cube_Input::was_input() {
  return has_input;
}

vector<vector<int>> Cube_Input::vomit_users_vector() {
  return users_cube;
}

bool Cube_Input::if_user_wants_input() {
  string what_wants = "";
  cout << "do you want to add the cube's status by hand?\n<y/n>" << endl;
  getline(cin, what_wants);
  return what_wants == "y" ? true : false;
}

void Cube_Input::get_input() {  
  char input;
  cout << "Do you want to enter the difficulty lvl <D>\nor do you want to enter the cube's status manually <M>\nor you want both <B>?" << endl;
  cin >> input;
  switch (int(input)) {
  case 68:
    cout << "Difficulty setup:" << endl;
    get_input_for_shuffle();
    break;
  case 78:
    cout << "Cube setup manually:" << endl;
    get_input_for_cube();
    break;
  case 66:
    cout << "Both:" << endl;
    get_input_for_shuffle();
    get_input_for_cube();
    break;
  }
}

void Cube_Input::get_input_for_shuffle() {
  cout << "enter the difficulty lvl:" << endl;
  cin >> shuffle;
  cout << shuffle << endl;
}

void Cube_Input::help() {
  cout << "the codes for the colors are:" << endl;
  cout << "green - G\nred - R\nblue - B\norange - O\nwhite - W\nyellow - Y" << endl;
  cout << "X for restart the side" << endl;
  cout << "Q for quitting input and starting random cube" << endl;
  cout << "every other character show this help again" << endl;
}

void Cube_Input::get_input_for_cube() {
  cout << "please put the cube down, \nwhite centered face upside,\ngreen centered face faceing you" << endl << endl;
  help();
  cout << endl << "enter the colors one-by-one for the ";
  for (int i = 0; i < order.size(); i++) {
    cout << order[i] << " side" << endl;
    evaluate();
  }
  cout << "finished" << endl;
}

void Cube_Input::evaluate() {
  while (side.size() < 9) {
    string color = "";
    getline(cin, color);
    switch (int(color[0])) {
    case 81:
      cout << "quit user input\nstarting random cube..." << endl;
      return;
    case 71:
      side.push_back(1);
      break;
    case 82:
      side.push_back(1);
      break;
    case 66:
      side.push_back(2);
      break;
    case 79:
      side.push_back(3);
      break;
    case 87:
      side.push_back(4);
      break;
    case 89:
      side.push_back(5);
      break;
    case 88:
      side.clear();
      break;
    default:
      help();
      break;
    }
  }
  users_cube.push_back(side);
  side.clear();
}

int Cube_Input::get_shuffle() {
  return shuffle;
}

Cube_Input::~Cube_Input() {
}
