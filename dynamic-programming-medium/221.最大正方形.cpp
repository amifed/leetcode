/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size(), col = matrix.size() > 0 ? matrix[0].size() : 0;
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    int ret = 0;
    for (int i = 1; i <= row; i++) {
      for (int j = 1; j <= col; j++) {
        if (matrix[i - 1][j - 1] == '1') {
          dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
          ret = max(ret, dp[i][j]);
        }
      }
    }
    return ret * ret;
  }
};
// @lc code=end
