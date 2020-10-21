#include <algodts/algos/is_valid_parentheses.hpp>
#include <testing/catch.hh>

TEST_CASE("Testing parentheses validity", "[parentheses]") {
  REQUIRE_FALSE(isValidParentheses("{}[]]"));
}
