#include <iostream>

#include "algos/is_palindrome.hpp"
#include "algos/my_atoi.hpp"
#include "algos/two_sum.hpp"

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
  return 0;
}