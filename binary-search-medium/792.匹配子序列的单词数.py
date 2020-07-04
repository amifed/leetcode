#
# @lc app=leetcode.cn id=792 lang=python3
#
# [792] 匹配子序列的单词数
#
from typing import List


# @lc code=start
class Solution:
    def numMatchingSubseq(self, S: str, words: List[str]) -> int:
        ret = 0
        heads = [[] for _ in range(26)]
        for word in words:
            it = iter(word)
            heads[ord(next(it)) - ord('a')].append(it)
        for c in S:
            index = ord(c) - ord('a')
            old = heads[index]
            heads[index] = []
            while old:
                it = old.pop()
                nxt = next(it, None)
                if nxt:
                    heads[ord(nxt) - ord('a')].append(it)
                else:
                    ret += 1

        return ret


# @lc code=end
