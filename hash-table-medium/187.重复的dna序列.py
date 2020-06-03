#
# @lc app=leetcode.cn id=187 lang=python3
#
# [187] 重复的DNA序列
#
from typing import List


# @lc code=start
class Solution:
    # hash
    # def findRepeatedDnaSequences(self, s: str) -> List[str]:
    #     hash_table = dict()
    #     for i in range(len(s) - 9):
    #         sub = s[i:i+10]
    #         hash_table[sub] = 1 + hash_table.get(sub, 0)
    #     return [key for key, value in hash_table.items() if value > 1]
    # Rabin-Karp 旋转哈希
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        L, n = 10, len(s)
        if n <= L:
            return []
        a = 4
        aL = a**L
        to_int = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
        nums = [to_int[c] for c in s]
        h = 0
        visited, ret = set(), set()
        for start in range(n - L + 1):
            if start:
                h = h * a - nums[start - 1] * aL + nums[start + L - 1]
            else:
                for i in range(L):
                    h = h * a + nums[i]
            if h in visited:
                ret.add(s[start:start+L])
            visited.add(h)
        return list(ret)

# @lc code=end
