#
# @lc app=leetcode.cn id=1217 lang=python3
#
# [1217] 玩筹码
#
from typing import List


# @lc code=start
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        odd = sum(1 for chip in chips if chip & 1 == 1)
        return min(odd, len(chips) - odd)
# @lc code=end
