#include <iostream>
#include <string>


using namespace std;

void rotate_right(char m[5][5], char r[5][5]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      r[i][j] = m[4-j][i];
    }
   }
}


int main() {
  char matrix[5][5] = {
    {' ', ' ', '#', ' ', ' '},
    {' ', '#', ' ', '#', ' '},
    {' ', '#', '#', '#', ' '},
    {' ', '#', ' ', '#', ' '},
    {' ', '#', ' ', '#', ' '}
  };

  char rotated_matrix[5][5];

  rotate_right(matrix, rotated_matrix);

  // write the rotate_right function that rotates the matrix to the left
  // so the program should print this:
  //
  // ####
  //   # #
  // ####


  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cout << rotated_matrix[i][j];
    }
    cout << endl;
  }

  return 0;
}
