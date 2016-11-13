/*
 * IntLinkedList.cpp
 *
 *  Created on: 2016.11.10.
 *      Author: caruzzo74
 */
#include "IntLinkedList.hpp"

using namespace std;

IntLinkedList::Node::Node(int data) {
  this->data = data;
  this->next = 0;
}

const int IntLinkedList::Node::getData() {
  return data;
}

IntLinkedList::Node* IntLinkedList::Node::getNext() {
  return next;
}

void IntLinkedList::Node::setData(int data) {
  this->data = data;
}

void IntLinkedList::Node::setNext(Node* next) {
  this->next = next;
}

IntLinkedList::Node::~Node() {
}

IntLinkedList::IntLinkedList(int mData) {
  firstNode = new Node(mData);
  IntList::setLength(IntList::getLength() + 1);
}

int IntLinkedList::getFirst() {
  return firstNode->getData();
}

int IntLinkedList::getLast() {
  Node* temp = firstNode;
  while (temp->getNext() != 0) {
    temp = temp->getNext();
  }
  return temp->getData();
}

void IntLinkedList::append(int _a) {
  Node* new_node = new Node(_a);
  Node* temp = firstNode;
  while (temp->getNext() != 0) {
    temp = temp->getNext();
  }
  temp->setNext(new_node);
  IntList::setLength(IntList::getLength() + 1);
}

void IntLinkedList::insert(int _idx, int _a) {
  int len = IntList::getLength();
  if (_idx > len) {
    cout << "The given index is out of range. Nothing to insert.\n";
    return;
  }
  if (_idx == len) {
    append(_a);
    return;
  }
  Node* new_node;
  if (_idx == 0) {
    new_node = new Node(firstNode->getData());
    firstNode->setData(_a);
    Node* temp_next = firstNode->getNext();
    firstNode->setNext(new_node);
    new_node->setNext(temp_next);
    IntList::setLength(len + 1);
    return;
  }
  Node* temp = firstNode;
  int counter = 1;
  while (counter !=_idx) {
    temp = temp->getNext();
    counter++;
  }
  Node* after = temp->getNext();
  new_node = new Node(_a);
  new_node->setNext(after);
  temp->setNext(new_node);
  setLength(len + 1);
}

bool IntLinkedList::isEmpty() {
  return IntList::getLength() == 0;
}

void IntLinkedList:: printList() {
  Node* temp = firstNode;
  cout << temp->getData() << ", ";
  while (temp->getNext() != 0) {
    temp = temp->getNext();
    cout << temp->getData() << ", ";
  }
  cout << "\n";
}

IntLinkedList::~IntLinkedList() {
  Node* temp = firstNode;
  Node* next;
  while (temp->getNext() != 0) {
    next = temp->getNext();
    temp->setNext(next->getNext());
    delete next;
  }
  delete temp;
}
