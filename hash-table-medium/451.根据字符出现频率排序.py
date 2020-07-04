#
# @lc app=leetcode.cn id=451 lang=python3
#
# [451] 根据字符出现频率排序
#
import collections


# @lc code=start
class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join(k * v for k, v in collections.Counter(s).most_common())
# @lc code=end
