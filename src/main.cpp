#include <iostream>

#include "algos/microsoft/is_palindrome.hpp"
#include "algos/microsoft/my_atoi.hpp"
#include "algos/microsoft/reverse_string.hpp"
#include "algos/microsoft/two_sum.hpp"

using namespace std;

int main() {
  vector<int> test{4, 1, 2, 1};
  vector<int> result = twoSum(test, 3);
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << endl;
  }
  if (!isPalindrome("Hello")) {
    cout << "False" << endl;
  } else {
    cout << "True" << endl;
  }
  cout << myAtoi("345 sfd") << endl;
  string test_str = "Hello World!";
  vector<char> test_vtr(test_str.begin(), test_str.end());
  reverseString(test_vtr);
  for (const char &c : test_vtr) {
    cout << c;
  }
  cout << endl;
  return 0;
}