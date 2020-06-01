#
# @lc app=leetcode.cn id=319 lang=python3
#
# [319] 灯泡开关
#
from math import sqrt


# @lc code=start
class Solution:
    def bulbSwitch(self, n: int) -> int:
        return int(sqrt(n))


# @lc code=end
Solution().bulbSwitch(1)
