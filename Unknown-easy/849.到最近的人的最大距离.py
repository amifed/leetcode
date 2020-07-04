#
# @lc app=leetcode.cn id=849 lang=python3
#
# [849] 到最近的人的最大距离
#
import itertools


# @lc code=start
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        ret = 0
        for seat, group in itertools.groupby(seats):
            if not seat:
                ret = max(ret, (len(list(group))+1)//2)
        return max(ret, seats.index(1), seats[::-1].index(1))
# @lc code=end
