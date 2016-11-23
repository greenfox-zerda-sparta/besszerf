#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;

template<class T, class P>
class Calculator {
  private:
    T item1;
    P item2;
  public:
    Calculator(T i1, P i2);
    double add();
    double substract();
    double multiply();
    double divide();
};

template<class T, class P>
Calculator<T, P>::Calculator(T i1, P i2) {
  item1 = i1;
  item2 = i2;
}

template<class T, class P>
double Calculator<T, P>::add() {
  return (double)item1+item2;
}

template<class T, class P>
double Calculator<T, P>::substract() {
  return (double)item1-item2;
}

template<class T, class P>
double Calculator<T, P>::multiply() {
  return (double)item1*item2;
}

template<class T, class P>
double Calculator<T, P>::divide() {
  if (item2 == 0) {
    throw 0;
  }
    return (double)item1/item2;
}

int main() {
  //Create a class template for a calculatoradd
  //it should have all the basic methods: add, subtract, multiply, divide
  //use exceptions to handle errors in special cases! (find the special cases!)
  Calculator<float, int> my_class(3.1415, 9);
  cout << my_class.add() << endl;
  cout << my_class.substract() << endl;
  cout << my_class.multiply() << endl;
  try {
    cout << my_class.divide() << endl;
  } catch (int e) {
    cout << "Error: division by " << e << "." << endl;
  }
  return 0;
}
