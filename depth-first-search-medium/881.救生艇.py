#
# @lc app=leetcode.cn id=881 lang=python3
#
# [881] 救生艇
#
from typing import List


# @lc code=start
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        l, r = 0, len(people)-1
        ret = 0
        while l <= r:
            ret += 1
            if people[l] + people[r] <= limit:
                l += 1
            r -= 1
        return ret
# @lc code=end
