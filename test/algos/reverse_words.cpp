#include "algodts/algos.hpp"
#include "testing/catch.hh"

using namespace std;

TEST_CASE("Reversing words", "[word]") {
  REQUIRE(reverseWords("Hello World!") == "World! Hello");
}