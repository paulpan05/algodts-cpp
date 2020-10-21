#include <algodts/impl/is_palindrome.hpp>
#include <testing/catch.hh>

TEST_CASE("Check if strings are palindromes", "[palindrome]") {
  REQUIRE(isPalindrome("AHDHA") == true);
}
