#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;

template<class T, class P>
class Example {
  private:
    T item1;
    P item2;
  public:
    Example(T i1, P i2);
    T get_item1();
    P get_item2();
    void set_item1(T item);
    void set_item2(P item);
};

template<class T, class P>
Example<T, P>::Example(T i1, P i2) {
  item1 = i1;
  item2 = i2;
}

template<class T, class P>
T Example<T, P>::get_item1() {
    return item1;
}

template<class T, class P>
P Example<T, P>::get_item2() {
    return item2;
}

template<class T, class P>
void Example<T, P>::set_item1(T item) {
    item1 = item;
}

template<class T, class P>
void Example<T, P>::set_item2(P item) {
    item2 = item;
}

int main() {
  //Create a simple class template which contains 2 item and has both a get and a set method for these!
  Example<int, float> my_class(2, 3.1415);
  my_class.set_item1(5);
  my_class.set_item2(4.8);
  cout << my_class.get_item1() << endl;
  cout << my_class.get_item2() << endl;
  return 0;
}
