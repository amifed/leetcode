/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    unordered_map<char, pair<int, int>> coord;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<string> cdir = {"U", "D", "L", "R"};
    string findPath(char s, char t) {
        queue<pair<char, string>> q;
        unordered_set<char> visited;
        q.push({s, ""});
        visited.insert(s);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node.first == t)
                return node.second;
            auto pos = coord[node.first];
            for (int i = 0; i < 4; i++) {
                int x = pos.first + dir[i][0], y = pos.second + dir[i][1];
                if ((x == 5 && y == 0 || -1 < x && x < 5 && -1 < y && y < 5) && visited.count(board[x][y]) == 0) {
                    q.push({board[x][y], node.second + cdir[i]});
                }
            }
        }
        return "";
    }

public:
    string alphabetBoardPath(string target) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].length(); j++)
                coord.insert({board[i][j], {i, j}});
        char s = 'a';
        string ret;
        for (int i = 0; i < target.length(); i++) {
            ret += findPath(s, target[i]) + "!";
            s = target[i];
        }
        return ret;
    }
};
// @lc code=end
