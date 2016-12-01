#include <iostream>
#include <string>
#include "rock.h"
#include "pop.h"
#include "reggae.h"
#include "jukebox.h"

using namespace std;

/*
                 Create a Song class

It should store the title and the artist of the song and also set these with it's constructor
It also should store it's rating

The songs can have 3 different genres:

Rock
Pop
Reggae
The Songs should be able to perform 2 operations:

Rate

 It should add a rating to the song, it should return with false if the rating is not between 1 and 5
 true otherwise. The Rock songs cannot have 1 as a rating. The Reggae songs cannot have 5 as a rating.
 Sorry for the opionated exercise :)

Get average rating

 It should return the average of all the given ratings
*/

string in_words[4] = {"Unspecified", "Rock", "Pop", "Reggae"};

int main() {

  Song* song1 = new Rock("Sweet Child O' Mine", "Guns&Roses");
  Song* song2 = new Pop("Like a virgin", "Madonna");
  Song* song3 = new Reggae("Redemption song", "Bob Marley");
  Song* song4 = new Song("Show them to me", "Rodney Carrington");
  Song* song5 = new Song("Joyride", "Roxette");
  Song* song6 = new Rock("Paradise city", "Guns&Roses");

  Jukebox jb;
  jb.add_song(*song1);
  jb.rate(*song1, 5);
  jb.rate(*song1, 1);
  jb.rate(*song1, 5);
  jb.add_song(*song2);
  jb.rate(*song2, 5);
  jb.rate(*song2, 1);
  jb.rate(*song2, 4);
  jb.add_song(*song3);
  jb.rate(*song3, 5);
  jb.rate(*song3, 4);
  jb.rate(*song3, 4);
  jb.add_song(*song4);
  jb.rate(*song4, 5);
  jb.rate(*song4, 5);
  jb.rate(*song4, 4);
  jb.add_song(*song5);
  jb.rate(*song5, 5);
  jb.rate(*song5, 3);
  jb.rate(*song5, 3);
  jb.add_song(*song6);
  jb.rate(*song6, 5);
  jb.rate(*song6, 5);
  jb.rate(*song6, 4);

  cout << "Songs:\n";
  cout << song1->print_song();
  cout << " Average rating: "<< song1->get_average_rating() << endl;
  cout << song2->print_song();
  cout << " Average rating: "<< song2->get_average_rating() << endl;
  cout << song3->print_song();
  cout << " Average rating: "<< song3->get_average_rating() << endl;
  cout << song4->print_song();
  cout << " Average rating: "<< song4->get_average_rating() << endl;
  cout << " Average rating of rock: " << jb.get_rating_by(ROCK) << endl;
  cout << " Top rated song: " << jb.get_top_rated_title() << endl;
  cout << " Top rated genre: " << jb.get_top_rated_genre() << endl;
  cout << " Average rating of Guns & Roses: " << jb.get_rating_by("Guns&Roses") << endl;

return 0;
}
