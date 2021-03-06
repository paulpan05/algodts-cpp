#ifndef KNAPSACK_HPP_
#define KNAPSACK_HPP_

#include <algorithm>
#include <vector>

int knapsack(std::vector<int>& values, std::vector<int>& weights,
             int capacity) {
  std::vector<std::vector<int>> dp_table(weights.size(),
                                         std::vector<int>(capacity + 1, 0));
  for (int i = 0; i < dp_table.size(); ++i) {
    for (int j = 0; j < dp_table[0].size(); ++j) {
      int top_val = 0, top_left_val = 0;
      if (i != 0) {
        top_val = dp_table[i - 1][j];
        if (j - weights[i] >= 0) {
          top_left_val = dp_table[i - 1][j - weights[i]];
        }
      }
      int cur_val = 0;
      if (j >= weights[i]) {
        cur_val = values[i];
      }
      dp_table[i][j] = std::max(top_left_val + cur_val, top_val);
    }
  }
  return dp_table[dp_table.size() - 1][dp_table[0].size() - 1];
}

#endif
