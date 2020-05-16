#include <iostream>

#include "algos/is_palindrome.hpp"
#include "algos/two_sum.hpp"

int main() {
  vector<int> test{4, 1, 2, 1};
  vector<int> result = twoSum(test, 3);
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i];
  }
  if (!isPalindrome("Hello")) {
    cout << "False";
  }
  return 0;
}