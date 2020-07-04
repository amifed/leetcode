/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int i = nums.size() - 2;
    while (i > -1 && nums[i] >= nums[i + 1])
      i--;
    if (i > -1) {
      int j = nums.size() - 1;
      while (j > -1 && nums[i] >= nums[j])
        j--;
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};
// @lc code=end
