/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    int l = 1, r = x, mid, ret;
    while (l <= r) {
      mid = l + (r - l) / 2;
      if (mid == x / mid)
        return mid;
      else if (mid > x / mid)
        r = mid - 1;
      else {
        l = mid + 1;
        ret = mid;
      }
    }
    return ret;
  }
};
// @lc code=end
