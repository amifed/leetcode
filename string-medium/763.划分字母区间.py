#
# @lc app=leetcode.cn id=763 lang=python3
#
# [763] 划分字母区间
#
from typing import List


# @lc code=start
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        last = dict()
        for i, c in enumerate(S):
            last[c] = i
        start, end = -1, 0
        ret = []
        for i, c in enumerate(S):
            end = max(end, last[c])
            if i == end:
                ret.append(end - start)
                start = i
        return ret
# @lc code=end
