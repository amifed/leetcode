#
# @lc app=leetcode.cn id=97 lang=python3
#
# [97] 交错字符串
#

# @lc code=start
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        dp = [False] * (n + 1)
        if m + n != len(s3):
            return False
        dp[0] = True
        for i in range(m+1):
            for j in range(n+1):
                p = i + j - 1
                if i > 0:
                    dp[j] &= s1[i-1] == s3[p]
                if j > 0:
                    dp[j] |= (dp[j-1] and s2[j-1] == s3[p])
        return dp[-1]
# @lc code=end
