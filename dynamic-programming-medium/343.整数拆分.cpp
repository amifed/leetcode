/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  // int integerBreak(int n) {
  //   int ret = 0;
  //   vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  //   for (int i = 1; i < n + 1; i++) {
  //     dp[i][1] = i, dp[i][i] = 1;
  //     for (int j = 2; j <= i; j++) {
  //       for (int k = 1; k < i; k++) {
  //         dp[i][j] = max(dp[i][j], k * dp[i - k][j - 1]);
  //       }
  //       ret = max(ret, dp[i][j]);
  //     }
  //   }
  //   return ret;
  // }
  int integerBreak(int n) {
    int ret = 0;
    vector<int> dp(n + 1, 1);
    for (int i = 3; i < n + 1; i++)
      for (int j = 1; j < i; j++)
        dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
    return dp[n]; 
  }
};
// @lc code=end