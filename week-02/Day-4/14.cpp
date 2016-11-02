#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "                        HANGMAN\n\n";
  char answer = 'a';
  do {
    cout << "     If you wanna play - enter 'y'\n     or to exit - enter 'x': ";
    cin >> answer;
    cout << endl;
  } while (!(answer == 'y' || answer == 'x'));

  string word_to_play = "HANGMAN";
  string display = "";
  char guessed_letter = '\0';
  int remaining_wrong_guesses = 5;
  bool is_a_good_try;

  for (int i = 0; i < word_to_play.length(); i++) {
    display += '_';
  }

   if (answer != 'x') {
    do {
      is_a_good_try = false;
      cout << "\nRemaining wrong guesses: " <<  remaining_wrong_guesses << "\n\n";
      cout << display << "\n\nGive me a letter /in capital/: ";
      cin >> guessed_letter;
      cout << endl;

      for (int i = 0; i < word_to_play.length(); i++) {
        if (word_to_play[i] == guessed_letter) {
          display[i] = guessed_letter;
          is_a_good_try = true;
        }
      }
      if (is_a_good_try) {
        if (word_to_play == display) {
          remaining_wrong_guesses = 5;
          cout << "You win! :)\nOne more? [y/n] " << endl;
          cin >> answer;
        }
      } else {
        remaining_wrong_guesses -= 1;
        if (remaining_wrong_guesses == 0) {
          remaining_wrong_guesses = 5;
          cout << "Game over! :(\nOne more? [y/n] " << endl;
          cin >> answer;
        }
      }
    } while (answer == 'y');
  }
  cout << "Bye!" << endl;
  // Create a program that playes hangman
  //
  // It should have a hardcoded word.
  // The user should be able to guess wrong five times
  //
  // It should request for letters like:
  // Give me a letter:
  //
  // If the word contains the letter:
  //
  // As an answer it should print the word in its current form like:
  // _PP_E
  // Remaining wrong guesses: 5
  //
  // If don't contains:
  //
  // It should reduce the remaing wrong guesses by one, and print the error:
  //
  // Wrong guess
  // Remaining wrong guesses 4
  //
  // If the user ran out of guesses, it should display: Game over! :(
  //
  // If the user figured out all the letters in the word it should display: You Win! :)
  //

  return 0;
}
