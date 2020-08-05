/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int row, col;
    int dirt[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>> &board, int r, int c) {
        board[r][c] = '#';
        for (int i = 0; i < 4; i++) {
            int x = r + dirt[i][0], y = c + dirt[i][1];
            if (-1 < x && x < row && -1 < y && y < col && board[x][y] == 'O') {
                board[x][y] = '#';
                dfs(board, x, y);
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        row = board.size(), col = board.size() == 0 ? 0 : board[0].size();
        if (row == 0 || col == 0) {
            return;
        }
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][col - 1] == 'O')
                dfs(board, i, col - 1);
        }
        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O')
                dfs(board, 0, i);
            if (board[row - 1][i] == 'O')
                dfs(board, row - 1, i);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
// @lc code=end
