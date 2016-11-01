#include <iostream>
#include <string>

using namespace std;

bool is_numeric (char c) {
  int i = c + 0;
  if (i > 57 || i < 48) {
    return false;
  } else {
    return true;
  }
}

bool is_legal( string x) {
  bool res = true;
  int num_of_points = 0;
  for (int i = 0; i < x.length(); i++) {
    if (!is_numeric(x[i])) {
      if (x[i] == '.') {
        num_of_points++;
        if (num_of_points > 1) {
          cout << x[i] << " is a bad1 input\n";
          res = false;
          break;
        }
      } else if (i == 0) {
          if (x[i]+0 != 45 && x[i]+0 != 34 && x[i] != '+' && x[i] != '.' && !is_numeric(x[i])) {
            cout << (int)x[i] << " is a bad2 input\n";
            res = false;
            break;
          }
      } else {
        cout << x[i] << " is a bad input\n";
        res = false;
        break;
      }
    }
  }
  return res;
}

int pos_of_dot (string x) {
  int res = x.length();
  int i = 0;
  for (; i < x.length(); i++) {
    if (x[i] == '.') {
      res = i;
      break;
    }
  }
  return res;
}



double string_to_number(string x) {
  if (!is_legal(x)) {
    cout << "Error - Input string does not represent a number.\nTry these formats: -0.2 or +0.2 or .2" << endl;
    return 0;
  }
  double res = 0;
  int dotPos = pos_of_dot(x);
  double mult;
  for (int i = 0; i < x.length(); i++) {
    mult = 1;
    if (x[i]+0 != 46 && x[i]+0 != 45 && i < dotPos) {
      for (int j = i; j < dotPos-1; j++) {
        mult *= 10;
      }
      res += (x[i]-48) * mult;
    } else if (x[i]+0 != 46 && x[i]+0 != 45 && i > dotPos) {
      for (int y = i; y > dotPos; y--) {
        mult /= 10;
      }
      res += (x[i]-48) * mult;
    }
  }
  if (x[0] == '-') {
    res *= -1;
  }
  return res;
}

int main() {
  // Implement a function that takes a string as an argument and converts it to a floating point number

  double number = string_to_number("-2.4");

  cout << number / 2 << endl; // should print -1.2

  return 0;
}
