/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i > -1; i--) {
            for (int j = n - 1; j > -1; j--) {
                if (i == m - 1 && j == n - 1)
                    dp[i][j] = max(1 - dungeon[i][j], 1);
                else if (i == m - 1 || j == n - 1)
                    dp[i][j] = max(dp[min(m - 1, i + 1)][min(n - 1, j + 1)] - dungeon[i][j], 1);
                else
                    dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
