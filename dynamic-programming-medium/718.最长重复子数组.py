#
# @lc app=leetcode.cn id=718 lang=python3
#
# [718] 最长重复子数组
#
from typing import List


# @lc code=start
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        m, n = len(A), len(B)
        dp = [[0] * (m+1) for _ in range(n+1)]
        ret = 0
        for i in range(1, m+1):
            for j in range(1, n+1):
                dp[i][j] = dp[i-1][j-1] + 1 if A[i-1] == B[j-1] else 0
                ret = max(ret, dp[i][j])
        return ret
# @lc code=end
