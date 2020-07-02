#
# @lc app=leetcode.cn id=581 lang=python3
#
# [581] 最短无序连续子数组
#
from typing import List


# @lc code=start
class Solution:
    # Time Limit Exceeded
    # def findUnsortedSubarray(self, nums: List[int]) -> int:
    #     """compare and choose"""
    #     left, right = len(nums) - 1, 0
    #     for i in range(len(nums)):
    #         for j in range(i+1, len(nums)):
    #             if nums[j] < nums[i]:
    #                 left = min(left, i)
    #                 right = max(right, j)
    #     return right - left + 1 if right > left else 0

    # def findUnsortedSubarray(self, nums: List[int]) -> int:
    #     """sort and compare"""
    #     nums_copy = sorted(nums[:])
    #     left, right = 0, len(nums)-1
    #     while left < right and nums[left] == nums_copy[left]:
    #         left += 1
    #     while left < right and nums[right] == nums_copy[right]:
    #         right -= 1
    #     return right - left + (left != right)

    def findUnsortedSubarray(self, nums: List[int]) -> int:
        """stack"""
        stack = list()
        left, right = len(nums), 0
        for i in range(len(nums)):
            while stack and nums[i] < nums[stack[-1]]:
                left = min(left, stack.pop())
            stack.append(i)

        stack.clear()
        for i in range(len(nums)-1, -1, -1):
            while stack and nums[i] > nums[stack[-1]]:
                right = max(right, stack.pop())
            stack.append(i)

        return right - left + 1 if right > left else 0

# @lc code=end
