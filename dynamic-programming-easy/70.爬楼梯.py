#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#

# @lc code=start
class Solution:
    # dp
    # def climbStairs(self, n: int) -> int:
    #     dp = [1] * (n+1)
    #     for i in range(2, n+1):
    #         dp[i] = dp[i-1] + dp[i-2]
    #     return dp[-1]
    def climbStairs(self, n: int) -> int:
        pre, cur = 1, 1
        for _ in range(2, n+1):
            pre, cur = cur, pre + cur
        return cur
# @lc code=end
