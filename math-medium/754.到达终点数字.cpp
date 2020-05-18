/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int reachNumber(int target) {
    target = abs(target);
    int k = 0;
    while (target > 0)
      target -= ++k;
    return target % 2 == 0 ? k : k + 1 + k % 2;
  }
};
// @lc code=end
