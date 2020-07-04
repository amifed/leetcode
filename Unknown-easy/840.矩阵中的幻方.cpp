/*
 * @lc app=leetcode.cn id=840 lang=cpp
 *
 * [840] 矩阵中的幻方
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool magic(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    int sum = 15;
    set<int> s = {a, b, c, d, e, f, g, h, i};
    if (sum == a + b + c && sum == d + e + f && sum == g + h + i &&
        sum == a + d + g && sum == b + e + h && sum == c + f + i &&
        sum == a + e + i && sum == c + e + g && s.size() == 9 &&
        s.find(0) == s.end())
      return true;
    return false;
  }
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int ret = 0;
    int row = grid.size(), col = grid.size() > 0 ? grid[0].size() : 0;
    for (int i = 1; i < row - 1; i++) {
      for (int j = 1; j < col - 1; j++) {
        if (grid[i][j] == 5) {
          ret += magic(grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1],
                       grid[i][j - 1], grid[i][j], grid[i][j + 1],
                       grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1]);
        }
      }
    }
    return ret;
  }
};
// @lc code=end
