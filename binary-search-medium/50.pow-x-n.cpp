/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  double fastPow(double x, long n) {
    if (n == 0) return 1.0;
    double half = fastPow(x, n / 2);
    if ((n & 1) == 1)
      return x * half * half;
    else
      return half * half;
  }
  double myPow(double x, int n) {
    return n < 0 ? 1 / fastPow(x, -(long)n) : fastPow(x, (long)n);
  }
};
// @lc code=end
// 1.00000\n-2147483648
