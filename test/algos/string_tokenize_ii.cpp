#include <algodts/algos/string_tokenize_ii.hpp>
#include <testing/catch.hh>

using namespace std;

TEST_CASE("Tokenize String II", "[string_tokenize_ii]") {
  string input = "Hello World!";
  char token = ' ';
  REQUIRE(string_tokenize_ii(input, token) ==
          vector<string>{"Hello", "World!"});
}