/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  // 二分查找
  // int findDuplicate(vector<int> &nums) {
  //   int n = nums.size();
  //   int l = 1, r = n - 1, ret = -1;
  //   while (l <= r) {
  //     int m = (r + l) >> 1;
  //     int cnt = 0;
  //     for (int i = 0; i < n; i++)
  //       cnt += nums[i] <= m;
  //     if (cnt <= m)
  //       l = m + 1;
  //     else {
  //       r = m - 1;
  //       ret = m;
  //     }
  //   }
  //   return ret;
  // }
  // 快慢指针
  int findDuplicate(vector<int> &nums) {
    int slow = 0, fast = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};
// @lc code=end
