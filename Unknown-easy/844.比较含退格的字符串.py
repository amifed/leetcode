#
# @lc app=leetcode.cn id=844 lang=python3
#
# [844] 比较含退格的字符串
#
from typing import List
import itertools


# @lc code=start
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        # def build(s: str) -> List[int]:
        #     stack = list()
        #     for i in s:
        #         if i.isalpha():
        #             stack.append(i)
        #         elif stack:
        #             stack.pop()
        #     return stack
        # return build(S) == build(T)
        def F(s: str):
            skip = 0
            for c in reversed(s):
                if c == '#':
                    skip += 1
                elif skip:
                    skip -= 1
                else:
                    yield c
        return all(x == y for x, y in itertools.zip_longest(F(S), F(T)))
# @lc code=end
