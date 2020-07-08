#
# @lc app=leetcode.cn id=908 lang=python3
#
# [908] 最小差值 I
#
from typing import List


# @lc code=start
class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        return max(0, max(A) - min(A) - 2*K)

# @lc code=end
