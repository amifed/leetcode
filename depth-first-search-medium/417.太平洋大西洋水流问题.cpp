/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
  int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
  bool area(int x, int y, int row, int col) {
    return x > -1 && x < row && y > -1 && y < col;
  }
  void dfs(vector<vector<int>> matrix, vector<vector<bool>> &reach, int row,
           int col, int x, int y) {
    reach[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int _x = x + dir[i][0], _y = y + dir[i][1];
      if (area(_x, _y, row, col) && matrix[x][y] <= matrix[_x][_y] &&
          !reach[_x][_y])
        dfs(matrix, reach, row, col, _x, _y);
    }
  }
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
    int row = matrix.size(), col = matrix.size() > 0 ? matrix[0].size() : 0;
    vector<vector<bool>> Pacific(row, vector<bool>(col, false));
    vector<vector<bool>> Atlantic(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++) {
      dfs(matrix, Pacific, row, col, i, 0);
      dfs(matrix, Atlantic, row, col, i, col - 1);
    }
    for (int i = 0; i < col; i++) {
      dfs(matrix, Pacific, row, col, 0, i);
      dfs(matrix, Atlantic, row, col, row - 1, i);
    }
    vector<vector<int>> ret;
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++)
        if (Pacific[i][j] && Atlantic[i][j])
          ret.push_back({i, j});
    return ret;
  }
};
// @lc code=end
