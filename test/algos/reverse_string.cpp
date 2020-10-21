#include <algodts/impl/reverse_string.hpp>
#include <testing/catch.hh>

using namespace std;

TEST_CASE("Reversing strings", "[string]") {
  vector<char> initial{'a', 'b', 'c'};
  vector<char> final{'c', 'b', 'a'};
  reverseString(initial);
  REQUIRE(initial == final);
}
