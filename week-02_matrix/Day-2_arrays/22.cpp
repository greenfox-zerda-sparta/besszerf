#include <iostream>
using namespace std;

bool includes (int num, int arr[10]){
  bool res = false;
  for (int i =0; i < 10; i++) {
    if (num == arr[i]) {
      res = true;
      break;
    }
  }
  return res;
}

int first_index_of (int num, int *array, int len){
  int res = -1;
  for (int i = 0; i < len; i++){
    if (array[i] == num) {
      res = i;
      break;
    }
  }
  return res;
}

int last_index_of (int num, int *array, int len){
  int res = -1;
  for (int i = len-1; i > 0; i--){
    if (array[i] == num) {
      res = i;
      break;
    }
  }
  return res;
}


//Create a function to tell You whether a certain number is part of a 10 long array of integers.
//Create an other function to give You the first index of a given integer in an array of integers.
//Create an other functions to give You the index of the last occurrence of the given integer in
//the array.If the array does not include the given integer this function should return -1.
//Do not duplicate functionality, use the functions You've created earlier instead of duplicating.
//Create 5 arrays, each 10 long filled with integers.
//Find the first and last occurrances of the integer: 14. And Print them out. If the array does not
//include the integr You should say so in words.
//The names of the functions should be "includes", "firstIndexOf", "lastIndexOf"
//Decide what should the function return. Void? Bool? Int? Float? Char?

int main(int argc, char** argv){

  int ar1[] = {1, 2, 3, 14, 14, 14, 26, 345, 987, 1111};
  int ar2[] = {1, 2, 3, 14, 14, 15, 26, 345, 987, 1111};
  int ar3[] = {1, 2, 3, 14, 14, 4, 26, 345, 987, 1111};
  int ar4[] = {1, 2, 3, 1, 1, 1, 26, 345, 987, 1111};
  int ar5[] = {1, 2, 3, 14, 14, 141, 26, 345, 987, 1111};

  if (!includes(14, ar4)) {
    cout << "The given array doesn't contain 14." << endl;
  } else {
    cout << "The given array contains 14." << endl;
  }

  cout << first_index_of(14, ar1, 10) << endl;
  cout << last_index_of(14, ar1, 10) << endl;
  return 0;
}
