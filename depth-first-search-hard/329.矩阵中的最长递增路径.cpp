/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int row, col;
    const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> memo;
    int dfs(vector<vector<int>> &matrix, int r, int c) {
        if (memo[r][c] != 0) return memo[r][c];
        for (auto v : dir) {
            int x = r + v[0], y = c + v[1];
            if (-1 < x && x < row && -1 < y && y < col && matrix[r][c] < matrix[x][y]) {
                memo[r][c] = max(memo[r][c], dfs(matrix, x, y));
            }
        }
        return ++memo[r][c];
    }
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        row = matrix.size(), col = matrix[0].size();
        memo.resize(row, vector<int>(col, 0));
        int ret = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ret = max(ret, dfs(matrix, i, j));
            }
        }
        return ret;
    }
};
// @lc code=end
