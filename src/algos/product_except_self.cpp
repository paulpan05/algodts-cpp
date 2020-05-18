#include "algos/product_except_self.hpp"

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> tmp(nums);
  if (nums.empty()) {
    return nums;
  }
  for (int i = 1; i < nums.size(); ++i) {
    nums[i] *= nums[i - 1];
  }
  nums[nums.size() - 1] = nums[nums.size() - 2];
  for (int i = nums.size() - 2; i > 0; --i) {
    tmp[i] *= tmp[i + 1];
    nums[i] = tmp[i + 1] * nums[i - 1];
  }
  nums[0] = tmp[1];
  return nums;
}
