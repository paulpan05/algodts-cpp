#include <algodts/algos.hpp>
#include <testing/catch.hh>

using namespace std;

TEST_CASE("Reversing word array", "[word]") {
  vector<char> words{'A', ' ', 'H'};
  vector<char> reversed{'H', ' ', 'A'};
  reverseWordsII(words);
  REQUIRE(words == reversed);
}