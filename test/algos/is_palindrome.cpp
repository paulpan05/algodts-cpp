#include "algodts/algos.hpp"
#include "testing/catch.hh"

TEST_CASE("Check if strings are palindromes", "[palindrome]") {
  REQUIRE(isPalindrome("AHDHA") == true);
}