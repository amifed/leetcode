/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class NumArray {
private:
  vector<int> dp;

public:
  NumArray(vector<int> &nums) {
    dp = vector<int>(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++)
      dp[i + 1] = dp[i] + nums[i];
  }

  int sumRange(int i, int j) { return dp[j + 1] - dp[i]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
// ["NumArray"]\n[[[]]]