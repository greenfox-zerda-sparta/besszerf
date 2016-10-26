#include <iostream>
using namespace std;

void sortAscending(int *array, int length);
// Implement this function to sort the array in an ascending order.

void sortDescending(int *array, int length);
// Implement this function to sort the array in a descending order.

void printArray(int *array, int length) {
  cout << "{";
  for(int i=0; i<length; i++){
    cout << array[i];
    if(i<length-1) {
      cout << ", ";
    }
  }
  cout << "}" << endl;
}



int main(int argc, char** argv){
  int example[13] = {34, 56, 26, 84, 29, 3875, 43, 96, 4759, 979, 92, 56, 1987};
  sortAscending(example, 13);
  printArray(example, 13);
  sortDescending(example, 13);
  printArray(example, 13);

  return 0;
}

void sortAscending(int *array, int length){
  int temp;
  bool arrayChanged;
    do {
    arrayChanged = 0;
    for (int i = 1; i < length; i++){
      if (*array > *(array+1)){
        temp = *array;
        *array = *(array+1);
        *(array+1) = temp;
        arrayChanged = 1;
      }
      array++;
    }
    array -= length-1;
  } while(arrayChanged);
}

void sortDescending(int *array, int length){
  int temp;
  bool arrayChanged;
    do {
    arrayChanged = 0;
    for (int i = 1; i < length; i++){
      if (*array < *(array+1)){
        temp = *array;
        *array = *(array+1);
        *(array+1) = temp;
        arrayChanged = 1;
      }
      array++;
    }
    array -= length-1;
  } while(arrayChanged);
}
