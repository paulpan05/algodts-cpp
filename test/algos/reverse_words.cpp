#include <algodts/algos/reverse_words.hpp>
#include <testing/catch.hh>

using namespace std;

TEST_CASE("Reversing words", "[word]") {
  string input = "Hello World!";
  REQUIRE(reverseWords(input) == "World! Hello");
}
