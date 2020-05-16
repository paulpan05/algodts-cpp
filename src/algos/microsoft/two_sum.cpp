#include "algos/microsoft/two_sum.hpp"

#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, vector<int>> unique_nums;

  for (int i = 0; i < nums.size(); ++i) {
    if (unique_nums.count(nums[i]) > 0) {
      unique_nums[nums[i]].push_back(i);
    } else {
      unique_nums.insert(make_pair(nums[i], vector<int>()));
      unique_nums[nums[i]].push_back(i);
    }
  }

  for (int i = 0; i < nums.size(); ++i) {
    if (unique_nums.count(target - nums[i]) > 0) {
      for (int j = 0; j < unique_nums[target - nums[i]].size(); ++j) {
        if (unique_nums[target - nums[i]][j] != i) {
          return vector<int>{i, unique_nums[target - nums[i]][j]};
        }
      }
    }
  }

  return vector<int>();
}