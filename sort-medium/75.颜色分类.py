#
# @lc app=leetcode.cn id=75 lang=python3
#
# [75] 颜色分类
#
from typing import List
import collections


# @lc code=start
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        counter = collections.Counter(nums)
        n = 0
        for i in range(3):
            for _ in range(counter[i]):
                nums[n] = i
                n += 1
# @lc code=end
