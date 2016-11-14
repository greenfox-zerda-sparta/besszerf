/*
 * rock.h
 *
 *  Created on: 2016.11.13.
 *      Author: caruzzo74
 */

#ifndef ROCK_H_
#define ROCK_H_
#include <string>
#include "song.h"

class Rock : public Song {
  public:
    Rock(std::string title, std::string artist);
    bool rate (int);
};

#endif /* ROCK_H_ */
