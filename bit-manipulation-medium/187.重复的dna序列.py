#
# @lc app=leetcode.cn id=187 lang=python3
#
# [187] 重复的DNA序列
#
from typing import List


# @lc code=start
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)
        if n <= L:
            return []
        to_int = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
        nums = [to_int[c] for c in s]
        bitmask = 0
        visited, ret = set(), set()
        for start in range(n - L + 1):
            if start:
                bitmask <<= 2
                bitmask |= nums[start + L - 1]
                bitmask &= ~(3 << 2 * L)
            else:
                for i in range(L):
                    bitmask <<= 2
                    bitmask |= nums[i]
            if bitmask in visited:
                ret.add(s[start:start+L])
            visited.add(bitmask)
        return list(ret)
# @lc code=end
