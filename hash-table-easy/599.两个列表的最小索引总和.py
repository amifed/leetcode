#
# @lc app=leetcode.cn id=599 lang=python3
#
# [599] 两个列表的最小索引总和
#
from typing import List


# @lc code=start
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        hash_table = {list1[i]: i for i in range(len(list1))}
        min_sum, ret = 2000, list()
        for i in range(len(list2)):
            cur_sum = i + hash_table.get(list2[i], 2000)
            if cur_sum == min_sum:
                ret.append(list2[i])
            elif cur_sum < min_sum:
                min_sum = cur_sum
                ret = list([list2[i]])
        return ret
# @lc code=end
