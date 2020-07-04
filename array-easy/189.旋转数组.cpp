/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  void rotate(vector<int>& nums, int k) {
    // k %= nums.size();
    // reverse(nums.begin(), nums.end() - k);
    // reverse(nums.end() - k, nums.end());
    // reverse(nums.begin(), nums.end());
    std::rotate(nums.begin(), nums.end() - k % nums.size(), nums.end());
  }
};
// @lc code=end
