/*
 * song.cpp
 *
 *  Created on: 2016.11.11.
 *      Author: caruzzo74
 */
#include <iostream>
#include <string>
#include "song.h"

using namespace std;

Song::Song() {
  this->title = "";
  this->artist = "";
  genre = UNSPECIFIED;
  num_of_ratings = 0;
  sum_of_ratings = 0;

}

Song::Song(string title, string artist) {
  this->title = title;
  this->artist = artist;
  genre = UNSPECIFIED;
  num_of_ratings = 0;
  sum_of_ratings = 0;
}

string Song::get_title() {
  return title;
}

string Song::get_artist() {
  return artist;
}

bool Song::rate(int _rate) {
  bool result = true;
  if (_rate < 1 || _rate >5) {
    return false;
  }
  num_of_ratings++;
  sum_of_ratings += _rate;
  return result;
}

float Song::get_average_rating() {
  return (float)sum_of_ratings / num_of_ratings;
}

int Song::get_num_of_ratings() const {
  return num_of_ratings;
}

int Song::get_sum_of_ratings() const {
  return sum_of_ratings;
}

int Song::get_genre() {
  return genre;
}

std::string Song::print_song() {
  std::string output = "";
  output += title + " - " + artist + " /";
  output += in_words[genre];
  output += "/;";
  return output;
}

Song::~Song(){}
