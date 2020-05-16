#include "algos/my_atoi.hpp"

#include "testing/catch.hh"

TEST_CASE("Strings are converted to numbers like atoi", "[atoi]") {
  REQUIRE(myAtoi("   121") == 121);
}