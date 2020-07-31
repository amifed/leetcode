#
# @lc app=leetcode.cn id=153 lang=python3
#
# [153] 寻找旋转排序数组中的最小值
#
from typing import List


# @lc code=start
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        if left == right or nums[left] < nums[right]:
            return nums[0]
        while left <= right:
            mid = left + ((right - left) >> 1)
            if nums[mid] > nums[mid + 1]:
                return nums[mid + 1]
            if nums[mid] < nums[mid - 1]:
                return nums[mid]
            if nums[mid] > nums[0]:
                left = mid + 1
            else:
                right = mid - 1
        return -1

    # def findMin(self, nums: List[int]) -> int:
    #     left, right = 0, len(nums) - 1
    #     while right > left:
    #         mid = left + (right - left) // 2
    #         if nums[mid] > nums[right]:
    #             left = mid + 1
    #         else:
    #             right = mid
    #     return nums[left]
# @lc code=end
