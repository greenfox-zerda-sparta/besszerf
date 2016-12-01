/*
 * jukebox.cpp
 *
 *  Created on: 2016.11.13.
 *      Author: caruzzo74
 */
#include <iostream>
#include "jukebox.h"

Jukebox::Jukebox() {
  song_count = 0;
  songs = 0;
}

void Jukebox::add_song(Song& song){
  Song** temp = new Song*[song_count + 1];
  if (songs != 0) {
    for (unsigned int i = 0; i < song_count; i++) {
      temp[i] = songs[i];
    }
  }
  temp[song_count] = &song;
  delete[] songs;
  songs = temp;
  song_count++;
}

void Jukebox::rate(Song& song, int _rate) {
  song.rate(_rate);
}

float Jukebox::get_rating_by(std::string artist) {
  if (songs != 0) {
    int sum_of_rates = 0;
    int rates = 0;
    for (unsigned int i = 0; i < song_count; i++) {
      if (songs[i]->get_artist() == artist) {
        sum_of_rates += songs[i]->get_sum_of_ratings();
        rates += songs[i]->get_num_of_ratings();
      }
    }
    return (float) sum_of_rates/rates;
  } else {
    return 0;
  }
}

float Jukebox::get_rating_by(int genre) {
  if (songs != 0) {
    int sum_of_rates = 0;
    int rates = 0;
    for (unsigned int i = 0; i < song_count; i++) {
      if (songs[i]->get_genre() == genre) {
        sum_of_rates += songs[i]->get_sum_of_ratings();
        rates += songs[i]->get_num_of_ratings();
      }
    }
    return (float) sum_of_rates/rates;
  } else {
    return 0;
  }
}

std::string Jukebox::get_top_rated_title() {
  if (songs != 0) {
    Song* top_rated = songs[0];
    for (unsigned int i = 0; i < song_count; i++) {
      if (songs[i]->get_average_rating() > top_rated->get_average_rating()) {
        top_rated = songs[i];
      }
    }
    return top_rated->get_title();
  } else {
    return "There are not songs!";
  }
}

std::string Jukebox::get_top_rated_genre() {
  if (songs != 0) {
    int top_rated = 0;
    float top_score = get_rating_by(0);
    for (unsigned int i = 0; i < sizeof(in_words)/sizeof(int); i++) {
      if (get_rating_by(i) > top_score) {
        top_rated = i;
      }
    }
    return in_words[top_rated];
  } else {
    return "There are not songs!";
  }
}
