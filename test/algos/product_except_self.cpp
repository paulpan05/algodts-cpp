#include "algodts/algos.hpp"
#include "testing/catch.hh"

using namespace std;

TEST_CASE("Testing product except self", "[product]") {
  vector<int> test{1, 2, 3, 4};
  vector<int> result{24, 12, 8, 6};
  REQUIRE(productExceptSelf(test) == result);
}