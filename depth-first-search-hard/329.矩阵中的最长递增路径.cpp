/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<int>> memo;
  int dfs(vector<vector<int>>& matrix, int x, int y, int row, int col) {
    if (memo[x][y] != 0) return memo[x][y];
    for (int i = 0; i < 4; i++) {
      int _x = x + dir[i][0], _y = y + dir[i][1];
      if (-1 < x && x < row && -1 < y && y < col &&
          matrix[_x][_y] > matrix[x][y])
        memo[x][y] = max(memo[x][y], dfs(matrix, _x, _y, row, col));
    }
    return ++memo[x][y];
  }
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    memo = vector<vector<int>>(row, vector<int>(col, 0));
    int ret = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        ret = max(ret, dfs(matrix, i, j, row, col));
      }
    }
    return ret;
  }
};
// @lc code=end
