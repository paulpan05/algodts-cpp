#include "algodts/algos.hpp"
#include "testing/catch.hh"

using namespace std;

TEST_CASE("Checks maximum value of knapsack", "[knapsack]") {
  vector<int> arr1{1, 2, 3};
  vector<int> arr2{1, 2, 3};
  REQUIRE(knapsack(arr1, arr2, 3) == 3);
}