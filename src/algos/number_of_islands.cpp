#include "algos/number_of_islands.hpp"

using namespace std;

void dfs(vector<vector<char>>& grid, int row, int column) {
  int rows = grid.size();
  int columns = grid[0].size();

  grid[row][column] = '0';
  if (row - 1 >= 0 && grid[row - 1][column] == '1') dfs(grid, row - 1, column);
  if (row + 1 < rows && grid[row + 1][column] == '1')
    dfs(grid, row + 1, column);
  if (column - 1 >= 0 && grid[row][column - 1] == '1')
    dfs(grid, row, column - 1);
  if (column + 1 < columns && grid[row][column + 1] == '1')
    dfs(grid, row, column + 1);
}

int numIslands(vector<vector<char>>& grid) {
  int rows = grid.size();
  if (!rows) return 0;
  int columns = grid[0].size();
  int num_islands = 0;
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < columns; ++c) {
      if (grid[r][c] == '1') {
        ++num_islands;
        dfs(grid, r, c);
      }
    }
  }
  return num_islands;
}
