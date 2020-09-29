#ifndef NUMISLANDS_HPP_
#define NUMISLANDS_HPP_

#include <functional>
#include <vector>

using namespace std;

int numIslands(vector<vector<char>>& grid) {
  function<void (int, int)> dfs = [&](int row, int column) {
    int rows = grid.size();
    int columns = grid[0].size();

    grid[row][column] = '0';
    if (row - 1 >= 0 && grid[row - 1][column] == '1')
      dfs(row - 1, column);
    if (row + 1 < rows && grid[row + 1][column] == '1')
      dfs(row + 1, column);
    if (column - 1 >= 0 && grid[row][column - 1] == '1')
      dfs(row, column - 1);
    if (column + 1 < columns && grid[row][column + 1] == '1')
      dfs(row, column + 1);
  };
  int rows = grid.size();
  if (!rows) return 0;
  int columns = grid[0].size();
  int num_islands = 0;
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < columns; ++c) {
      if (grid[r][c] == '1') {
        ++num_islands;
        dfs(r, c);
      }
    }
  }
  return num_islands;
}

#endif