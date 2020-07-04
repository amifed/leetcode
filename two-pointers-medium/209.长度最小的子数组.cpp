/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int minSubArrayLen(int s, vector<int> nums) {
    int n = nums.size();
    int l = 0, r = 0, sum = 0, ret = INT_MAX;
    while (r < n) {
      sum += nums[r++];
      while (l < n && sum >= s) {
        ret = min(ret, r - l);
        sum -= nums[l++];
      }
    }
    return ret == INT_MAX ? 0 : ret;
  }
};
// @lc code=end