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
    void bfs(vector<vector<char>> &board, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        board[r][c] = '#';
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = node.first + dirt[i][0], y = node.second + dirt[i][1];
                if (-1 < x && x < row && -1 < y && y < col && board[x][y] == 'O') {
                    q.push({x, y});
                    board[x][y] = '#';
                }
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
                bfs(board, i, 0);
            if (board[i][col - 1] == 'O')
                bfs(board, i, col - 1);
        }
        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O')
                bfs(board, 0, i);
            if (board[row - 1][i] == 'O')
                bfs(board, row - 1, i);
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
int main(int argc, char const *argv[]) {
    vector<vector<char>> v = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    Solution().solve(v);
    return 0;
}
