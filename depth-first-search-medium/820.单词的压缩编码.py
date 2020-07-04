#
# @lc app=leetcode.cn id=820 lang=python3
#
# [820] 单词的压缩编码
#
from typing import List


# @lc code=start
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        good = set(words)
        for word in words:
            for i in range(1, len(word)):
                good.discard(word[i:])
        return sum(len(word) + 1 for word in good)
# @lc code=end
