#
# @lc app=leetcode.cn id=75 lang=python3
#
# [75] 颜色分类
#
from typing import List


# @lc code=start
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p0, p, p2 = 0, 0, len(nums) - 1
        while p <= p2:
            if nums[p] == 0:
                nums[p], nums[p0] = nums[p0], nums[p]
                p0 += 1
                p += 1
            elif nums[p] == 2:
                nums[p], nums[p2] = nums[p2], nums[p]
                p2 -= 1
            else:
                p += 1
# @lc code=end
