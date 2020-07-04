/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  bool checkPossibility(vector<int> &nums) {
    int size = nums.size();
    bool change = false;
    for (int i = 1; i < size; i++) {
      if (nums[i - 1] > nums[i]) {
        if (change)
          return false;
        if (i - 2 > -1 && nums[i - 2] > nums[i])
          nums[i] = nums[i - 1];
        else
          nums[i - 1] = nums[i];
        change = true;
      }
    }
    return true;
  }
};
// @lc code=end
