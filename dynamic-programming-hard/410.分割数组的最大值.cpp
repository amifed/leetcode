/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = j - 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], prefix[i] - prefix[k]));
                }
            }
        }
        return int(dp[n][m]);
    }
};
// @lc code=end
