#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "apple.h"

TEST_CASE("Test apple") {
  Apple apple;
  REQUIRE (apple.get_apple() == "Apple");
}
