/*
 * pop.cpp
 *
 *  Created on: 2016.11.13.
 *      Author: caruzzo74
 */

#include "pop.h"

Pop::Pop(std::string title, std::string artist) : Song(title, artist) {
  genre = POP;
}

