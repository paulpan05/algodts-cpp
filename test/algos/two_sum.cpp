#include <algodts/algos/two_sum.hpp>
#include <testing/catch.hh>

using namespace std;

TEST_CASE("Get the indices of 2 values in array that add up to target",
          "[index]") {
  vector<int> nums{1, 2, 3, 4};
  int target = 7;
  vector<int> result{2, 3};
  REQUIRE(twoSum(nums, target) == result);
}
