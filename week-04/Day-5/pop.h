/*
 * pop.h
 *
 *  Created on: 2016.11.13.
 *      Author: caruzzo74
 */

#ifndef POP_H_
#define POP_H_

#include <string>
#include "song.h"

class Pop : public Song {
  public:
    Pop(std::string title, std::string artist);
};

#endif /* POP_H_ */
