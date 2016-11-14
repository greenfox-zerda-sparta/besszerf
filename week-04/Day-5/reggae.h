/*
 * raggae.h
 *
 *  Created on: 2016.11.13.
 *      Author: caruzzo74
 */

#ifndef REGGAE_H_
#define REGGAE_H_
#include <string>
#include "song.h"

class Reggae : public Song {
  public:
    Reggae(std::string title, std::string artist);
    bool rate (int);
};
#endif /* REGGAE_H_ */
