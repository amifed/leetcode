#
# @lc app=leetcode.cn id=931 lang=python3
#
# [931] 下降路径最小和
#
from typing import List


# @lc code=start
class Solution:
    # 自顶向下
    # def minFallingPathSum(self, A: List[List[int]]) -> int:
    #     n = len(A)
    #     for i in range(1, n):
    #         for j in range(n):
    #             if j == 0:
    #                 A[i][j] += min(A[i-1][j], A[i-1][j+1])
    #             elif j == n - 1:
    #                 A[i][j] += min(A[i-1][j], A[i-1][j-1])
    #             else:
    #                 A[i][j] += min(A[i-1][j-1], A[i-1][j], A[i-1][j+1])
    #     return min(A[n-1])
    # 自顶向下 V2
    # def minFallingPathSum(self, A: List[List[int]]) -> int:
    #     n = len(A)
    #     for i in range(1, n):
    #         for j in range(n):
    #             row = A[i-1]
    #             A[i][j] += min(row[max(0, j-1):min(n, j+2)])
    #     return min(A[n-1])
    # 自底向下
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        while len(A) > 1:
            row = A.pop()
            for i in range(len(row)):
                A[-1][i] += min(row[max(0, i-1):min(len(row), i+2)])
        return min(A[0])


# @lc code=end
