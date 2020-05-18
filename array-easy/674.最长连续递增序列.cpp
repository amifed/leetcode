/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    if(nums.size() == 0) return 0;
    int ret = 1, cnt = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1])
        cnt++;
      else
        cnt = 1;
      ret = max(ret, cnt);
    }
    return ret;
  }
};
// @lc code=end
