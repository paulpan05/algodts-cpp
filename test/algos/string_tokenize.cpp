#include <algodts/algos/string_tokenize.hpp>
#include <testing/catch.hh>

using namespace std;

TEST_CASE("Tokenize String", "[string_tokenize]") {
  string input = "Hello World!";
  string token = " ";
  REQUIRE(string_tokenize(input, token) == vector<string>{"Hello", "World!"});
}
