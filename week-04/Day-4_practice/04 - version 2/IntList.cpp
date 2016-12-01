/*
 * IntList.cpp
 *
 *  Created on: 2016.11.10.
 *      Author: caruzzo74
 */
#include "IntList.hpp"

IntList::IntList() {
  mLength = 0;
}

const int IntList::getLength() {
  return mLength;
}

void IntList::setLength(int _l) {
  mLength = _l;
}

IntList::~IntList() {}
