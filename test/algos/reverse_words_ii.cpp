#include "algos/reverse_words_ii.hpp"

#include "testing/catch.hh"

using namespace std;

TEST_CASE("Reversing word array", "[word]") {
  vector<char> words{'A', ' ', 'H'};
  vector<char> reversed{'H', ' ', 'A'};
  reverseWords(words);
  REQUIRE(words == reversed);
}