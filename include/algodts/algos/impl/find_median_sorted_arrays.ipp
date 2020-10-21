#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1,
                              std::vector<int>& nums2) {
  std::vector<int> medians;
  int total_length = nums1.size() + nums2.size();
  int middle = (total_length - 1) / 2;
  medians.emplace_back(middle);
  if (total_length % 2 == 0) {
    medians.emplace_back(middle + 1);
  }
  double total_medians = 0;
  int m = 0, n = 0;
  bool isNums2 = false;
  for (int i = 0; i < total_length; ++i) {
    if (m >= nums1.size()) {
      isNums2 = true;
    } else if (n >= nums2.size()) {
      isNums2 = false;
    } else if (nums1[m] < nums2[n]) {
      isNums2 = false;
    } else {
      isNums2 = true;
    }
    if (medians.size() == 2 && i == medians[1]) {
      if (isNums2) {
        total_medians += nums2[n];
        break;
      } else {
        total_medians += nums1[m];
        break;
      }
    } else if (i == medians[0]) {
      if (isNums2) {
        total_medians += nums2[n];
      } else {
        total_medians += nums1[m];
      }
      if (medians.size() == 1) {
        break;
      }
    }
    if (isNums2) {
      n += 1;
    } else {
      m += 1;
    }
  }
  return total_medians / medians.size();
}