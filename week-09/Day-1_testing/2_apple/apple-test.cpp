#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "apple.h"
#include <vector>

TEST_CASE("Test apple") {
  Apple apple;
  vector<int> a;
  for (int i = 0; i < 10; ++i) {
    a.push_back(1);
  }
  REQUIRE (apple.sum_apples(a) == 10);
}

TEST_CASE("Test apple with 0 elements") {
  Apple apple;
  vector<int> a;
  REQUIRE (apple.sum_apples(a) == 0);
}

TEST_CASE("Test apple with 1 element") {
  Apple apple;
  vector<int> a;
    a.push_back(5);
  REQUIRE (apple.sum_apples(a) == 5);
}
