/*
 * raggae.cpp
 *
 *  Created on: 2016.11.13.
 *      Author: caruzzo74
 */

#include <iostream>

#include "reggae.h"

Reggae::Reggae(std::string title, std::string artist) : Song(title, artist) {
  genre = 3;
}

bool Reggae::rate(int _rate) {
  if (_rate == 5) {
    std::cout << "Reggae can not get rate 5. Sorry." << std::endl;
    return false;
  }
  return Song::rate(_rate);
}
