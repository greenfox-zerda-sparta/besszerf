#include <iostream>
#include <string>
using namespace std;

// Create a function like macro, that gets an expression as it's input.
// If the expression is false, it should print out some error message.
#define myAssert(a) if(!(a)) {cout<<"You are an asshole!"<<endl;}

int main() {
  int x = 3;
  myAssert(x == 2);
  return 0;
}
