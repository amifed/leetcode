#
# @lc app=leetcode.cn id=884 lang=python3
#
# [884] 两句话中的不常见单词
#
from typing import List


# @lc code=start
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        str_map = {}
        for i in A.split(' '):
            str_map[i] = str_map.get(i, 0) + 1
        for i in B.split(' '):
            str_map[i] = str_map.get(i, 0) + 1
        return [i for i in str_map if str_map[i] == 1]
# @lc code=end
