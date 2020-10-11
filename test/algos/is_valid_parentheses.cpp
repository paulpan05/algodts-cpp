#include <algodts/algos.hpp>
#include <testing/catch.hh>

TEST_CASE("Testing parentheses validity", "[parentheses]") {
  REQUIRE_FALSE(isValidParentheses("{}[]]"));
}