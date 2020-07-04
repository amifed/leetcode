/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  // int countNumbersWithUniqueDigits(int n) {
  //   vector<int> dp(n + 1);
  //   dp[0] = 1;
  //   int factor = 9, product = 9;
  //   for (int i = 1; i <= n; i++) {
  //     dp[i] = dp[i - 1] + product;
  //     product *= factor, factor--;
  //   }
  //   return dp[n];
  // }
  // 优化
  int countNumbersWithUniqueDigits(int n) {
    vector<int> dp(n + 1);
    int cur = 1, per = 1, factor = 9, product = 9;
    for (int i = 1; i <= n; i++) {
      cur = per + product;
      per = cur, product *= factor, factor--;
    }
    return cur;
  }
};
// @lc code=end
