/*
 * song.h
 *
 *  Created on: 2016.11.11.
 *      Author: caruzzo74
 */

#ifndef SONG_H_
#define SONG_H_
#include <string>
#include "util.h"

class Song {
  private:
    std::string title;
    std::string artist;
    int sum_of_ratings;
    int num_of_ratings;
  protected:
    int genre;
  public:
    Song();
    Song(std::string title, std::string artist);
    virtual bool rate(int);
    float get_average_rating();
    std::string get_title();
    std::string get_artist();
    int get_num_of_ratings() const;
    int get_sum_of_ratings() const;
    int get_genre();
    std::string print_song();
    virtual ~Song();
};

#endif /* SONG_H_ */
