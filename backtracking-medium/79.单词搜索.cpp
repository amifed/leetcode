/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //上 右 下 左
    bool backtracking(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, int row, int col, int index) {
        if (index == word.length()) return true;
        if (board[row][col] != word[index]) return false;
        visited[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int x = row + dir[i][0], y = col + dir[i][1];
            if (-1 < x && x < board.size() && -1 < y && y < board[0].size() && !visited[x][y]) {
                if (backtracking(board, word, visited, x, y, index + 1))
                    return true;
            }
        }
        visited[row][col] = false;
        return index + 1 == word.length();
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (backtracking(board, word, visited, i, j, 0)) return true;
        return false;
    }
};
// @lc code=end
