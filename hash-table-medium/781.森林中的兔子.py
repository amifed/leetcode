#
# @lc app=leetcode.cn id=781 lang=python3
#
# [781] 森林中的兔子
#
import collections
from typing import List


# @lc code=start
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        return sum(-v % (k+1) + v for k, v in collections.Counter(answers).most_common())
# @lc code=end
