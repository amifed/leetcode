/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size(), col = matrix.size() == 0 ? 0 : matrix[0].size();
        if (row == 0 || col == 0) {
            return matrix;
        }
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> dist(row, vector<int>(col, 0));
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = p.first + dirs[i][0], y = p.second + dirs[i][1];
                if (-1 < x && x < row && -1 < y && y < col && !visited[x][y]) {
                    dist[x][y] = dist[p.first][p.second] + 1;
                    q.emplace(x, y);
                    visited[x][y] = true;
                }
            }
        }
        return dist;
    }
};
// @lc code=end