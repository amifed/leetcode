#
# @lc app=leetcode.cn id=198 lang=python3
#
# [198] 打家劫舍
#
from typing import List


# @lc code=start
# class Solution:
#     def rob(self, nums: List[int]) -> int:
#         if not nums:
#             return 0
#         size = len(nums)
#         if size == 1:
#             return nums[0]
#         dp = [0] * size
#         dp[0] = nums[0]
#         dp[1] = max(nums[0], nums[1])
#         for i in range(2, size):
#             dp[i] = max(dp[i-1], dp[i-2]+nums[i])
#         return dp[size-1]
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        size = len(nums)
        if size == 1:
            return nums[0]
        first, second = nums[0], max(nums[0], nums[1])
        for i in range(2, size):
            first, second = second, max(first+nums[i], second)
        return second
# @lc code=end
