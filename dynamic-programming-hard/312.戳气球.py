#
# @lc app=leetcode.cn id=312 lang=python3
#
# [312] 戳气球
#
from typing import List


# @lc code=start
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        val = [1] + nums + [1]
        dp = [[0] * (n + 2) for _ in range(n + 2)]
        for i in range(n, -1, -1):
            for j in range(i+1, n+2):
                for k in range(i+1, j):
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k]
                                   [j]+val[i]*val[k]*val[j])
        return dp[0][-1]
# @lc code=end
