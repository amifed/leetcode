/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
    int row = matrix.size(), col = matrix.size() > 0 ? matrix[0].size() : 0;
    vector<vector<int>> pacificAtlantic(row, vector<int>(col, 0));
    vector<vector<int>> ret;
    int direct[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    queue<pair<int, int>> Q;
    for (int i = 0; i < row; i++) {
      Q.push({i, 0});
      pacificAtlantic[i][0] |= 1;
      Q.push({i, col - 1});
      pacificAtlantic[i][col - 1] |= 2;
    }
    for (int i = 0; i < col; i++) {
      Q.push({0, i});
      pacificAtlantic[0][i] |= 1;
      Q.push({row - 1, i});
      pacificAtlantic[row - 1][i] |= 2;
    }
    while (!Q.empty()) {
      pair<int, int> pos = Q.front();
      Q.pop();
      for (int i = 0; i < 4; i++) {
        int x = pos.first + direct[i][0], y = pos.second + direct[i][1];
        if (x < 0 || y < 0 || x >= row || y >= col ||
            matrix[pos.first][pos.second] > matrix[x][y] ||
            pacificAtlantic[pos.first][pos.second] == pacificAtlantic[x][y])
          continue;
        pacificAtlantic[x][y] |= pacificAtlantic[pos.first][pos.second];
        Q.push({x, y});
      }
    }
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        if (pacificAtlantic[i][j] == 3)
          ret.push_back({i, j});
    return ret;
  }
};
// @lc code=end
