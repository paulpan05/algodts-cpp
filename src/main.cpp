#include <iostream>

#include "algos/two_sum.hpp"

using namespace std;

int main() {
  vector<int> test{4, 1, 2, 1};
  vector<int> result = twoSum(test, 3);
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i];
  }
  return 0;
}