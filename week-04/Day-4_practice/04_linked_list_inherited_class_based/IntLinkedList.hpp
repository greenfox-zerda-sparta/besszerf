/*
 * IntLinkedList.hpp
 *
 *  Created on: 2016.11.10.
 *      Author: caruzzo74
 */

#ifndef INTLINKEDLIST_HPP_
#define INTLINKEDLIST_HPP_
#include "IntList.hpp"
#include <iostream>

using namespace std;

// Inherit from IntList and create an implementation that uses an Nodes to store list elements!

class Node {
  private:
    int data;
    Node* next;

  public:
    Node(int dat);
    void setData(int _dat);
    void setNext(Node* _nod);
    const int getData();
    Node* getNext();
    ~Node();
};

class IntLinkedList : public IntList {

  private:
    Node* firstNode;

  public:
    IntLinkedList(int mData);
    void append(int _a);
    void insert(int _idx, int _a);
    int getFirst();
    int getLast();
    bool isEmpty();
    void printList();
    ~IntLinkedList();
};

#endif /* INTLINKEDLIST_HPP_ */
