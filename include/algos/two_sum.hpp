#ifndef TWOSUM_HPP_
#define TWOSUM_HPP_

#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i];
    if (map.find(complement) != map.end()) {
      return {map[complement], i};
    }
    map.emplace(nums[i], i);
  }
  return {};
}

#endif