#include <iostream>
#include <string>

#include "IntList.hpp"
#include "IntLinkedList.hpp"

using namespace std;

// Take the attached hpp and cpp files. Read them trough.
// Choose either IntArrayList or IntLinkedList and implement it.
// Write code here in a main function that uses it and tests it in edge cases as well.

int main() {
  IntLinkedList* theList = new IntLinkedList(5); //Your code starts here!
  for (int i = 0; i < 4; i++) {
    theList->append(4-i);
  }
  theList->insert(0, 9);
  cout << "Length of the list: " << theList->getLength() << endl;
  cout << "First element of the list: " << theList->getFirst() << endl;
  cout << "Last element of the list: " << theList->getLast() << endl;
  cout << "Elements one by one: ";
  theList->printList();
  delete theList;
return 0;
}
