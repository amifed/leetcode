/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int numDistinct(string s, string t) {
    int len_s = s.length(), len_t = t.length();
    vector<vector<long>> dp(len_s + 1, vector<long>(len_t + 1, 0));
    for (int i = 0; i <= len_s; i++)
      dp[i][0] = 1;
    for (int i = 1; i <= len_s; i++) {
      for (int j = 1; j <= len_t; j++) {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[len_s][len_t];
  }
};
// @lc code=end
