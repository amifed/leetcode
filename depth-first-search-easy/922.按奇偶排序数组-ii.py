#
# @lc app=leetcode.cn id=922 lang=python3
#
# [922] 按奇偶排序数组 II
#
from typing import List


# @lc code=start
class Solution:
    # def sortArrayByParityII(self, A: List[int]) -> List[int]:
    #     ret = [0] * len(A)
    #     i, j = 0, 1
    #     for k in A:
    #         if (k & 1) == 0:
    #             ret[i] = k
    #             i += 2
    #         else:
    #             ret[j] = k
    #             j += 2
    #     return ret
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        j = 1
        for i in range(0, len(A), 2):
            if A[i] & 1:
                while A[j] & 1:
                    j += 2
                A[i], A[j] = A[j], A[i]
        return A
# @lc code=end
