/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int dfs(vector<vector<int>>& matrix, int i, int j, int row, int col,
          vector<vector<int>>& memo) {
    if (memo[i][j] != 0) return memo[i][j];
    for (int d = 0; d < 4; d++) {
      int x = i + dir[d][0], y = j + dir[d][1];
      if (-1 < x && x < row && -1 < y && y < col && matrix[x][y] > matrix[i][j])
        memo[i][j] = max(memo[i][j], dfs(matrix, x, y, row, col, memo));
    }
    return ++memo[i][j];
  }
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int row = matrix.size(), col = matrix[0].size();
    vector<vector<int>> memo(row, vector<int>(col, 0));
    int ret = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        ret = max(ret, dfs(matrix, i, j, row, col, memo));
      }
    }
    return ret;
  }
};
// @lc code=end
