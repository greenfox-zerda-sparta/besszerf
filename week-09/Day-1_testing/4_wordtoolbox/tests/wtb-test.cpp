#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../src/wordtoolbox.h"
#include "../src/catch.hpp"

TEST_CASE("WordToolbox Tarzan") {
WordToolbox wSource("Tarzan's toenails");
REQUIRE(wSource.countHowMany('a') == 3);
REQUIRE(wSource.countHowMany('T') == 1);
REQUIRE(wSource.countHowMany('t') == 1);
REQUIRE(wSource.countHowMany('x') == 0);
REQUIRE(wSource.countHowMany(' ') == 1);
}

TEST_CASE("WordToolbox Tarzan and Jane") {
WordToolbox wSource("Tarzan's toenails");
wSource.setS(wSource.getS() + " Me Tarzan, You Jane");
REQUIRE(wSource.countHowMany('a') == 6);
REQUIRE(wSource.countHowMany('T') == 2);
REQUIRE(wSource.countHowMany('t') == 1);
REQUIRE(wSource.countHowMany('x') == 0);
REQUIRE(wSource.countHowMany(' ') == 5);
}

TEST_CASE("Anagram") {
WordToolbox wSource("floate");
string S = "folate";
string alternatives[6] = {"falsetto", "latest", "foetal","aloft","float","flota"};
CHECK(wSource.isAnAnagram(S) == false);
  for (uint i = 0; i < 6; ++i) {
    wSource.setS(alternatives[i]);
    CHECK(wSource.isAnAnagram(S) == false);
  }
}

