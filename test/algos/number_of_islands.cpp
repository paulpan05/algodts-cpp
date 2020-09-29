#include "algodts/algos.hpp"
#include "testing/catch.hh"

using namespace std;

TEST_CASE("Checks number of islands in 2d array", "[num_islands]") {
  vector<vector<char>> arr{{'1', '0', '0'}, {'1', '0', '0'}, {'1', '0', '0'}};
  REQUIRE(numIslands(arr) == 1);
}
