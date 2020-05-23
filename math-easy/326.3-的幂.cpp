/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  //循环
  // bool isPowerOfThree(int n) {
  //   long m = 1;
  //   while (m < n) {
  //     m *= 3;
  //   }
  //   return n == m;
  // }
  // 换底公式
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;
    double ret = log10(n) / log10(3);
    return (ret - int(ret)) < 1e-13;
  }
  // 递归
  // bool isPowerOfThree(int n) {
  //   if (n <= 0)
  //     return false;
  //   else if (n == 1)
  //     return true;
  //   else
  //     return n % 3 == 0 && isPowerOfThree(n / 3);
  // }
};
// @lc code=end
