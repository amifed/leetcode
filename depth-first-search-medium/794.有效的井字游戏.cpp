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
    unordered_set<pair<int, int>> us;
    bool isValid(vector<string> &board, char chess) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == chess && board[i][1] == chess && board[i][2] == chess)
                return true;
            if (board[0][i] == chess && board[1][i] == chess && board[2][i] == chess)
                return true;
        }
        if (board[0][0] == chess && board[1][1] == chess && board[2][2] == chess)
            return true;
        if (board[0][2] == chess && board[1][1] == chess && board[2][0] == chess)
            return true;
        return false;
    }
    bool recursive(vector<string> &board, char chess) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (us.count({i, j}) == 0)
            }
        }
    }

public:
    bool validTicTacToe(vector<string> &board) {
    }
};
// @lc code=end
