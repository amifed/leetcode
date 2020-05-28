# @before-stub-for-debug-begin
from python3problem771 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=771 lang=python3
#
# [771] 宝石与石头
#

# @lc code=start


class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return sum(c in J for c in S)
# @lc code=end
