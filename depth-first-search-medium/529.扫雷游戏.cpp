/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        int r = click[0], c = click[1];
        int row = board.size(), col = board[0].size();
        if (board[r][c] == 'M' || board[r][c] == 'X') {
            board[r][c] = 'X';
            return board;
        }
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int x = r + dx[i], y = c + dy[i];
            if (-1 < x && x < row && -1 < y && y < col && board[x][y] == 'M') {
                cnt++;
            }
        }
        if (cnt > 0) {
            board[r][c] = cnt + '0';
            return board;
        }
        board[r][c] = 'B';
        for (int i = 0; i < 8; i++) {
            int x = r + dx[i], y = c + dy[i];
            if (-1 < x && x < row && -1 < y && y < col && board[x][y] == 'E') {
                vector<int> nex = {x, y};
                updateBoard(board, nex);
            }
        }
        return board;
    }
};
// @lc code=end
