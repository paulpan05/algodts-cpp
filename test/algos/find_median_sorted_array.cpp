#include <algodts/impl/find_median_sorted_arrays.hpp>
#include <testing/catch.hh>

using namespace std;

TEST_CASE("Checks median of sorted array", "[median_sorted]") {
  vector<int> arr1{1, 2};
  vector<int> arr2{3, 4};
  REQUIRE(findMedianSortedArrays(arr1, arr2) == 2.5);
}
