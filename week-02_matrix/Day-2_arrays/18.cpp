#include <iostream>
using namespace std;

inline int numOfEvens(int nums[], int len){
  int evs = 0;
  for(int i = 0; i < len; i++){
    if (nums[i] % 2 == 0) {
      evs += 1;
    }
  }
  return evs;
}
int main(){
  int numbers[] = {4, 5, 6, 2, 3, 8, 6, 5};
  // create a function that takes an array and it's length as an agrument
  // and returns a number that states how many even numbers are in the array
  cout << numOfEvens(numbers, sizeof(numbers)/sizeof(int)) << endl;
  return 0;
}
