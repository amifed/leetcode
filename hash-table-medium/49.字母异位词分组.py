#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#
from typing import List
import collections


# @lc code=start
class Solution:
    # def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    #     ret = collections.defaultdict(list)
    #     for s in strs:
    #         ret[tuple(sorted(s))].append(s)
    #     return list(ret.values())
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ret = collections.defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            ret[tuple(count)].append(s)
        return list(ret.values())
# @lc code=end
