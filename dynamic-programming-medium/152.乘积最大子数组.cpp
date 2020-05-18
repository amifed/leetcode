/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int ret = nums[0], imax = nums[0], imin = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < 0) swap(imax, imin);
      imax = max(imax * nums[i], nums[i]);
      imin = min(imin * nums[i], nums[i]);
      ret = max(ret, imax);
    }
    return ret;
  }
};
// @lc code=end
