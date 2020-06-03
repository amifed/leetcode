/*
 * @lc app=leetcode.cn id=837 lang=cpp
 *
 * [837] 新21点
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  double new21Game(int N, int K, int W) {
    vector<double> dp(K + W);
    double sum = 0;
    for (int i = K; i < K + W; i++) {
      dp[i] = i > N ? 0 : 1.0;
      sum += dp[i];
    }
    for (int i = K - 1; i > -1; i--) {
      dp[i] = sum / W;
      sum = sum - dp[i + W] + dp[i];
    }
    return dp[0];
  }
};
// @lc code=end
