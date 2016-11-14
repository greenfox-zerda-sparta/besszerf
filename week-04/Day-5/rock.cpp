/*
 * rock.cpp
 *
 *  Created on: 2016.11.13.
 *      Author: caruzzo74
 */
#include <iostream>
#include "rock.h"

Rock::Rock(std::string title, std::string artist) : Song(title, artist) {
  genre = 1;
}

bool Rock::rate(int _rate) {
  if (_rate == 1) {
    std::cout << "Rock can not get rate 1. Sorry." << std::endl;
    return false;
  }
  return Song::rate(_rate);
}

