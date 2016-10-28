#include <iostream>
#include <string>

// Create a game that figures a number that the user picked between 0 and 10
// It should ask questions like:
//  - Is the number greater than 5? [y/n]
//  - Is the number smaller than 4? [y/n]
// (don't have to ask both kind)
//
// It should wait for input after the question
//
// If the answer is not "y" or "n" it should re-ask the question;
//
// If the program knows enough it should tell the picked number like:
// Your number is: 8

using namespace std;

int count_new_guess(int min, int max) {
  return (min+max)/2;
}

void reset_game(int &my_guess, int &high, int &low, int first_guess, int first_high, int first_low, bool &direction
){
  my_guess = first_guess;
  high = first_high;
  low = first_low;
  direction = true;
}

int main() {
  const int first_high = 11;
  const int first_low = -1;

  const int first_guess = (first_high + first_low)/2;
  int my_guess = first_guess;
  int high = first_high;
  int low = first_low;
  char answer;
  bool stop = false;
  bool is_direction_of_guess_up = true;

  cout << "Pick a number between 0 and 10 and enter an alphanumeric character: ";
  cin >> answer;
  do {
    is_direction_of_guess_up && cout << endl << "Is the number greater than " << my_guess << "? [y/n] ";
    !is_direction_of_guess_up && cout << endl << "Is the number smaller than " << my_guess << "? [y/n] ";
    cin >> answer;
    if (answer == 'n') {
      if (!is_direction_of_guess_up) {
        my_guess--;
      } else {
        my_guess++;
      }
      is_direction_of_guess_up = !is_direction_of_guess_up;
    } else if (answer != 'y') {
        continue;
    }
    if (is_direction_of_guess_up) {
        low = my_guess;
    } else {
      high = my_guess;
    }
//    cout << high << low;
    my_guess = count_new_guess(low, high);
    if (my_guess == low+1 && !is_direction_of_guess_up) {
      is_direction_of_guess_up = !is_direction_of_guess_up;
      cout << " !";
    }
//    cout << my_guess;
    if (
        my_guess + 1 == high &&
        my_guess - 1 == low

        ) {
      cout << "\nYour number is: " << my_guess << endl << "One more? [y/n] ";
//      cin >> answer;
      if (answer == 'y') {
        reset_game(my_guess, high, low, first_guess, first_high, first_low, is_direction_of_guess_up);
      } else {
        stop = true;
      }
    }
  } while (!stop);
  cout << "\nBye!\n";
  return 0;
}
