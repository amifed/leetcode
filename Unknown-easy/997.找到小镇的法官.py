#
# @lc app=leetcode.cn id=997 lang=python3
#
# [997] 找到小镇的法官
#
from typing import List
import collections


# @lc code=start
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        inn, out = [0] * (N+1), [0] * (N+1)
        for a, b in trust:
            out[a] += 1
            inn[b] += 1
        for i in range(1, N+1):
            if inn[i] == N - 1 and out[i] == 0:
                return i
        return -1
# @lc code=end
