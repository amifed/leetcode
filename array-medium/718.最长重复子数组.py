#
# @lc app=leetcode.cn id=718 lang=python3
#
# [718] 最长重复子数组
#
from typing import List


# @lc code=start
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        def max_length(addA: int, addB: int, length: int) -> int:
            ret = k = 0
            for i in range(length):
                if A[addA + i] == B[addB + i]:
                    k += 1
                    ret = max(ret, k)
                else:
                    k = 0
            return ret

        m, n = len(A), len(B)
        ret = 0
        for i in range(m):
            ret = max(ret, max_length(i, 0, min(m-i, n)))
        for i in range(n):
            ret = max(ret, max_length(0, i, min(n-i, m)))
        return ret
# @lc code=end
