/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    int x1 = coordinates[1][0] - coordinates[0][0];
    int y1 = coordinates[1][1] - coordinates[0][1];
    for (int i = 2; i < coordinates.size(); i++) {
      int x2 = coordinates[i][0] - coordinates[0][0];
      int y2 = coordinates[i][1] - coordinates[0][1];
      if (x1 * y2 != x2 * y1)
        return false;
    }
    return true;
  }
};
// @lc code=end
