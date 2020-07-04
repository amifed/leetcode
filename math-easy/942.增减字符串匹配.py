#
# @lc app=leetcode.cn id=942 lang=python3
#
# [942] 增减字符串匹配
#
from typing import List


# @lc code=start
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        low, high = 0, len(S)
        ret = list()
        for c in S:
            if c == 'I':
                ret.append(low)
                low += 1
            else:
                ret.append(high)
                high -= 1

        return ret + [low]
# @lc code=end
