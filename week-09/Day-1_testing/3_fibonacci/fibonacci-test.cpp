#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "fibonacci.h"

TEST_CASE("Fibonacci 0th") {
  Fibonacci fibonacci;
REQUIRE(fibonacci.get_number(0) == 0);
}

TEST_CASE("Fibonacci 4th") {
  Fibonacci fibonacci;
REQUIRE(fibonacci.get_number(4) == 3);
}

TEST_CASE("Fibonacci 5th") {
  Fibonacci fibonacci;
REQUIRE(fibonacci.get_number(5) == 5);
}

TEST_CASE("Fibonacci 6th") {
  Fibonacci fibonacci;
REQUIRE(fibonacci.get_number(6) == 8);
}

TEST_CASE("Fibonacci 8th") {
  Fibonacci fibonacci;
REQUIRE(fibonacci.get_number(8) == 21);
}

TEST_CASE("Fibonacci 1st") {
  Fibonacci fibonacci;
REQUIRE(fibonacci.get_number(1) == 1);
}


