#include <iostream>
using namespace std;

void safeUnion(int *a, int l_a, int *b, int l_b, int *result, int l_res) {
  // Implement this function to create the union of a and b into the array result!
  bool test = 0;
  for (int i = 0; i < l_a; i++) {
    for (int j = 0; j < l_b; j++) {
      if (*a == *b){
        test = 1;
      }
      b++;
    }
    b -= l_b;
    if (test == 0) {
      *result = *a;
      result++;
    }
    a++;
    test = 0;
  }
  for (int i = 0; i < l_b; i++) {
    *result = *(b);
    b++;
    result++;
  }
  return;
}

int main(int argc, char** argv) {
  int a[3] = {1,2,3};
  int b[3] = {4,5,6};
  int c[6];
  safeUnion(a,3,b,3,c,6);
  for (int i = 0; i<6; i++) cout <<c[i] << endl;

}
