#
# @lc app=leetcode.cn id=32 lang=python3
#
# [32] 最长有效括号
#

# @lc code=start
class Solution:
    # def longestValidParentheses(self, s: str) -> int:
    #    """dp"""
    #     dp = [0] * len(s)
    #     ret = 0
    #     for i in range(1, len(s)):
    #         if s[i] == ')':
    #             if s[i-1] == '(':
    #                 dp[i] = 2 + (dp[i-2] if i - 2 > -1 else 0)
    #             elif i - dp[i-1] > 0 and s[i - dp[i-1] - 1] == '(':
    #                 dp[i] = 2 + dp[i-1] + (dp[i - dp[i-1] - 2] if i -
    #                                        dp[i-1] - 2 > -1 else 0)
    #             ret = max(ret, dp[i])
    #     return ret

    # def longestValidParentheses(self, s: str) -> int:
    #     """stack"""
    #     ret = 0
    #     stack = [-1]
    #     for i in range(len(s)):
    #         if s[i] == '(':
    #             stack.append(i)
    #         else:
    #             stack.pop()
    #             if stack:
    #                 ret = max(ret, i - stack[-1])
    #             else:
    #                 stack.append(i)
    #     return ret

    def longestValidParentheses(self, s: str) -> int:
        """count"""
        left = right = ret = 0
        for i in range(len(s)):
            left += (s[i] == '(')
            right += (s[i] == ')')
            if left == right:
                ret = max(ret, 2*left)
            elif right > left:
                left = right = 0

        left = right = 0
        for i in range(len(s)-1, -1, -1):
            left += (s[i] == '(')
            right += (s[i] == ')')
            if left == right:
                ret = max(ret, 2*right)
            elif left > right:
                left = right = 0
        return ret

# @lc code=end
