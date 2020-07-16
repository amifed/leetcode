/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    bool isWin(vector<string> &board, char play) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == play && board[i][1] == play && board[i][2] == play)
                return true;
            if (board[0][i] == play && board[1][i] == play && board[2][i] == play)
                return true;
        }
        if (board[0][0] == play && board[1][1] == play && board[2][2] == play)
            return true;
        if (board[0][2] == play && board[1][1] == play && board[2][0] == play)
            return true;
        return false;
    }

public:
    bool validTicTacToe(vector<string> &board) {
        int x = 0, o = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                x += board[i][j] == 'X';
                o += board[i][j] == 'O';
            }
        }
        if (x != o && x != o + 1) return false;
        if (isWin(board, 'X') && x != o + 1) return false;
        if (isWin(board, 'O') && x != o) return false;
        return true;
    }
};
// @lc code=end