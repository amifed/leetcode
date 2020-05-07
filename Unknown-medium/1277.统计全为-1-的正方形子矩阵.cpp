/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int ret = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (matrix[i - 1][j - 1] == 1)
          ret += dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
    return ret;
  }
};
// @lc code=end
