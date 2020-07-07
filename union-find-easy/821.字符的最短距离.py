#
# @lc app=leetcode.cn id=821 lang=python3
#
# [821] 字符的最短距离
#
from typing import List


# @lc code=start
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        left = float('-inf')
        right = list(reversed([i for i, c in enumerate(S) if c == C]))
        right.insert(0, float('inf'))
        ret = list()
        for i in range(len(S)):
            ret.append(min(i-left, right[-1]-i))
            if S[i] == C:
                left = i
            if i == right[-1]:
                right.pop()
        return ret


# @lc code=end
Solution().shortestToChar("loveleetcode", 'e')
