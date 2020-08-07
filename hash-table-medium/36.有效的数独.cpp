/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            int row[9] = {0}, col[9] = {0}, matrix[9] = {0};
            for (int j = 0; j < 9; j++) {
                // row
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    if (row[num]) return false;
                    row[num]++;
                }

                // col
                if (board[j][i] != '.') {
                    int num = board[j][i] - '1';
                    if (col[num]) return false;
                    col[num]++;
                }

                // matrix
                int x = i / 3 * 3 + j / 3, y = i % 3 * 3 + j % 3;
                if (board[x][y] != '.') {
                    int num = board[x][y] - '1';
                    if (matrix[num]) return false;
                    matrix[num]++;
                }
            }
        }
        return true;
    }
};
// @lc code=end