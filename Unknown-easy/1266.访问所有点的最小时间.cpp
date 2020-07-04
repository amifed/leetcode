/*
 * @lc app=leetcode.cn id=1266 lang=cpp
 *
 * [1266] 访问所有点的最小时间
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int ret = 0, x = 0, y = 0;
    for (int i = 1; i < points.size(); i++) {
      x = abs(points[i][0] - points[i - 1][0]);
      y = abs(points[i][1] - points[i - 1][1]);
      ret += max(x, y);
    }
    return ret;
  }
};
// @lc code=end
