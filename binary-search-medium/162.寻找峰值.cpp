/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int search(vector<int> nums, int l, int r) {
    if (l == r)
      return l;
    int m = l + (r - l) / 2;
    if (nums[m] > nums[m + 1])
      return search(nums, l, m);
    return search(nums, m + 1, r);
  }
  int findPeakElement(vector<int> &nums) {
    // return search(nums, 0, nums.size() - 1);
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > nums[m + 1])
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
// @lc code=end
