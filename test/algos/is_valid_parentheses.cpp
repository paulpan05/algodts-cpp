#include <algodts/algos/is_valid_parentheses.hpp>
#include <testing/catch.hh>

using namespace std;

TEST_CASE("Testing parentheses validity", "[parentheses]") {
  string input = "{}[]]";
  REQUIRE_FALSE(isValidParentheses(input));
}
