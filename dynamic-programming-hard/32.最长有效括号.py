#
# @lc app=leetcode.cn id=32 lang=python3
#
# [32] 最长有效括号
#

# @lc code=start
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0] * len(s)
        ret = 0
        for i in range(1, len(s)):
            if s[i] == ')':
                if s[i-1] == '(':
                    dp[i] = 2 + (dp[i-2] if i - 2 > -1 else 0)
                elif i - dp[i-1] > 0 and s[i - dp[i-1] - 1] == '(':
                    dp[i] = 2 + dp[i-1] + (dp[i - dp[i-1] - 2] if i -
                                           dp[i-1] - 2 > -1 else 0)
                ret = max(ret, dp[i])
        return ret
# @lc code=end
