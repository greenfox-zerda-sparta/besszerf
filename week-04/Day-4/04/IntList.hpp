/*
 * IntList.hpp
 *
 *  Created on: 2016.11.10.
 *      Author: caruzzo74
 */

#ifndef INT_LIST_HPP
#define INT_LIST_HPP

class IntList {
  private:
    int mLength;

  protected:
    void setLength(int _l);

  public:
    IntList();
    virtual void append(int _a) = 0;
    virtual void insert(int _idx, int _a) = 0;
    virtual int getFirst() = 0;
    virtual int getLast() = 0;
    const int getLength();
    virtual bool isEmpty() = 0;

    virtual ~IntList();

};

#endif

