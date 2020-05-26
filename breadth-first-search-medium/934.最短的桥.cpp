/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
  int row, col;
  int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  queue<pair<int, int>> queue;

public:
  int shortestBridge(vector<vector<int>> &A) {
    row = A.size(), col = A[0].size();
    dyeing(A);
    int ret = 0;
    while (!queue.empty()) {
      int n = queue.size();
      for (int i = 0; i < n; i++) {
        auto p = queue.front();
        queue.pop();
        for (int j = 0; j < 4; j++) {
          int x = p.first + dir[j][0], y = p.second + dir[j][1];
          if (x < 0 || x >= row || y < 0 || y >= col || A[x][y] == 2)
            continue;
          if (A[x][y] == 1)
            return ret;
          A[x][y] = 2;
          queue.push({x, y});
        }
      }
      ret++;
    }
    return ret;
  }
  void dyeing(vector<vector<int>> &A) {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (A[i][j] == 1) {
          dfs(A, i, j);
          return;
        }
      }
    }
  }
  void dfs(vector<vector<int>> &A, int _x, int _y) {
    A[_x][_y] = 2;
    queue.push({_x, _y});
    for (int i = 0; i < 4; i++) {
      int x = _x + dir[i][0], y = _y + dir[i][1];
      if (x > -1 && x < row && y > -1 && y < col && A[x][y] == 1)
        dfs(A, x, y);
    }
  }
};
// @lc code=end
