/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int dfs(vector<vector<int>> &grid, int row, int col, int x, int y) {
    if (x < 0 || y < 0 || x >= row || y >= col)
      return 0;
    if (grid[x][y] == 1)
      return 1;
    int ret = 1;
    grid[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      ret = min(ret, dfs(grid, row, col, x + dir[i][0], y + dir[i][1]));
    }
    return ret;
  }
  int bfs(vector<vector<int>> &grid, int row, int col, int x, int y) {
    int ret = 1;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    while (!Q.empty()) {
      pair<int, int> pos = Q.front();
      Q.pop();
      grid[pos.first][pos.second] = 1;
      for (int d = 0; d < 4; d++) {
        int i = pos.first + dir[d][0], j = pos.second + dir[d][1];
        if (i < 0 || j < 0 || i >= row || j >= col) {
          ret = 0;
          continue;
        }
        if (grid[i][j] == 0)
          Q.push({i, j});
      }
    }
    return ret;
  }
  int closedIsland(vector<vector<int>> &grid) {
    int ret = 0;
    int row = grid.size(), col = grid[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 0)
          ret += bfs(grid, row, col, i, j);
      }
    }
    return ret;
  }
};
// @lc code=end
