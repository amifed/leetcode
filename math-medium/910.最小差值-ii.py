#
# @lc app=leetcode.cn id=910 lang=python3
#
# [910] 最小差值 II
#
from typing import List


# @lc code=start
class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        A.sort()
        ret = A[-1] - A[0]
        for i in range(len(A)-1):
            maxx = max(A[i] + K, A[-1] - K)
            minn = min(A[0] + K, A[i+1] - K)
            ret = min(ret, maxx - minn)
        return ret
# @lc code=end
