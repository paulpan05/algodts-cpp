#include <algodts/algos/is_palindrome.hpp>
#include <testing/catch.hh>

using namespace std;

TEST_CASE("Check if strings are palindromes", "[palindrome]") {
  string input = "AHDHA";
  REQUIRE(isPalindrome(input));
}
