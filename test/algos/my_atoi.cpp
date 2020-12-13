#include <algodts/algos/my_atoi.hpp>
#include <testing/catch.hh>

using namespace std;

TEST_CASE("Strings are converted to numbers like atoi", "[atoi]") {
  string input = "   121";
  REQUIRE(myAtoi(input) == 121);
}
