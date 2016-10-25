#include <iostream>
#include <string>

using namespace std;

void rowMatrix(int x[3][3]) {

	for (int i = 0; i < 3; i++){
		for (int z = 0; z < 3; z++) {
			cout <<	x[i][z] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}
void colMatrix(int x[3][3]) {

	for (int i = 0; i < 3; i++){
		for (int z = 0; z < 3; z++) {
			cout <<	x[z][i] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}
void printLine(int x[3][3]) {

  for (int i = 0; i < 3; i++){
    for (int z = 0; z < 3; z++) {
      cout <<	x[i][z] << "|";
    }
  }
  cout << endl;
  return;
}
void printCol(int x[3][3]) {

  for (int i = 0; i < 3; i++){
    for (int z = 0; z < 3; z++) {
      cout <<	x[i][z] << endl;
    }
  }
  return;
}

int main(){
  int m[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
		//This is an array of arrays. Print it out as a 3x3 matrix. Using each inner array as
		//a.) a row
		//b.) a column
		//c.) all in one line separated by the character '|'
		//d.) all in one column

  rowMatrix(m);
  colMatrix(m);
  printLine(m);
  printCol(m);

  return 0;
}