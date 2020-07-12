/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        int row = heightMap.size(), col = heightMap[0].size();
        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, -1, 1};
        using P = pair<int, int>;
        using PP = pair<int, P>;
        priority_queue<PP, vector<PP>, greater<PP>> pq;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    pq.push(PP(heightMap[i][j], P(i, j)));
                    visited[i][j] = 1;
                }
        int ret = 0;
        while (!pq.empty()) {
            PP pp = pq.top();
            P p = pp.second;
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int x = p.first + r[i], y = p.second + c[i];
                if (-1 < x && x < row && -1 < y && y < col && visited[x][y] == 0) {
                    if (pp.first > heightMap[x][y])
                        ret += pp.first - heightMap[x][y];
                    visited[x][y] = 1;
                    pq.push(PP(max(pp.first, heightMap[x][y]), P(x, y)));
                }
            }
        }
        return ret;
    }
};
// @lc code=end