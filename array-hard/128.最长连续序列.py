#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#
from typing import List


# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longest_streak = 0
        nums_set = set(nums)
        for num in nums:
            if num - 1 not in nums_set:
                current_num = num
                current_streak = 1
                while current_num + 1 in nums_set:
                    current_num += 1
                    current_streak += 1
                longest_streak = max(longest_streak,current_streak)
        return longest_streak
# @lc code=end

