/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        if (grid[0][0] == 1) return -1;
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        int ret = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (node.first == row - 1 && node.second == col - 1) return ret;
                for (auto v : dir) {
                    int x = node.first + v[0], y = node.second + v[1];
                    if (-1 < x && x < row && -1 < y && y < col && grid[x][y] != 1) {
                        q.push(make_pair(x, y));
                        grid[x][y] = 1;
                    }
                }
            }
            ret++;
        }
        return -1;
    }
};
// @lc code=end
