/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    double sum = 0;
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    double ret = sum;
    for (int i = 0, j = k; j < nums.size(); i++, j++) {
      sum += nums[j] - nums[i];
      ret = max(ret, sum);
    }
    return ret / k;
  }
};
// @lc code=end
