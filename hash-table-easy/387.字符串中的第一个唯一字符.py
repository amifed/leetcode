#
# @lc app=leetcode.cn id=387 lang=python3
#
# [387] 字符串中的第一个唯一字符
#
import collections


# @lc code=start
class Solution:
    def firstUniqChar(self, s: str) -> int:
        # s_map = collections.defaultdict(list)
        # for i, c in enumerate(s):
        #     s_map[c].append(i)
        # for m in s_map:
        #     if len(s_map[m]) == 1:
        #         return s_map[m][0]
        # return -1
        counter = collections.Counter(s)
        for i, c in enumerate(s):
            if counter[c] == 1:
                return i
        return -1
# @lc code=end
