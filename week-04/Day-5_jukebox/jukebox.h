/*
 * jukebox.h
 *
 *  Created on: 2016.11.13.
 *      Author: caruzzo74
 */

#ifndef JUKEBOX_H_
#define JUKEBOX_H_
#include "song.h"
#include "util.h"

class Jukebox {
  private:
    Song** songs;
    unsigned int song_count;
  public:
    Jukebox();
    void add_song(Song& song);
    void rate(Song& song, int _rate);
    float get_rating_by(std::string artist);
    float get_rating_by(int genre);
    std::string get_top_rated_title();
    std::string get_top_rated_genre();
};



#endif /* JUKEBOX_H_ */
