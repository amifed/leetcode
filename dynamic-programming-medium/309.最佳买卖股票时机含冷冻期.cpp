/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if (n == 0) {
            return 0;
        }
        // 0 no, 1 has, 2 freeze
        vector<vector<int>> f(n, vector<int>(3));
        f[0][1] = -p[0];
        f[0][0] = f[0][2] = 0;
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2]);
            f[i][1] = max(f[i - 1][0] - p[i], f[i - 1][1]);
            f[i][2] = f[i - 1][1] + p[i];
        }
        return max(f[n - 1][0], f[n - 1][2]);
    }
};
// @lc code=end

