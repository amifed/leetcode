#
# @lc app=leetcode.cn id=1002 lang=python3
#
# [1002] 查找常用字符
#
from typing import List
import collections
import functools


# @lc code=start
class Solution:
    # def commonChars(self, A: List[str]) -> List[str]:
    #     ret = list()
    #     for c in set(A[0]):
    #         for i in c * min([word.count(c) for word in A]):
    #             ret.append(i)
    #     return ret
    def commonChars(self, A: List[str]) -> List[str]:
        # ret = collections.Counter(A[0])
        # for i in range(1, len(A)):
        #     ret &= collections.Counter(A[i])
        # return ret.elements()
        return functools.reduce(lambda x, y: x & y, map(collections.Counter, A)).elements()

# @lc code=end
