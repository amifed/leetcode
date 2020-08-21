/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = m == 0 ? 0 : obstacleGrid[0].size();
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<int> f(n);
        f[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                } else if (j != 0) {
                    f[j] += f[j - 1];
                }
            }
        }
        return f[n - 1];
    }
};
// @lc code=end
