#
# @lc app=leetcode.cn id=1331 lang=python3
#
# [1331] 数组序号转换
#
from typing import List


# @lc code=start
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        hash_map = dict()
        sorted_list = sorted(list(set(arr)))
        for i, e in enumerate(sorted_list):
            hash_map[e] = i + 1
        return [hash_map[i] for i in arr]
# @lc code=end
