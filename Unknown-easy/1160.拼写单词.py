#
# @lc app=leetcode.cn id=1160 lang=python3
#
# [1160] 拼写单词
#
import collections
from typing import List


# @lc code=start
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        # counter = collections.Counter(chars)
        # return sum([len(word) for word in words if collections.Counter(word) - counter == collections.Counter()])
        chars_cnt = collections.Counter(chars)
        ret = 0
        for word in words:
            word_cnt = collections.Counter(word)
            for c in word_cnt:
                if chars_cnt[c] < word_cnt[c]:
                    break
            else:
                ret += len(word)
        return ret
# @lc code=end
