#
# @lc app=leetcode.cn id=456 lang=python3
#
# [456] 132模式
#
from typing import List


# @lc code=start
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3:
            return False
        mins, stack = list([nums[0]]), list()
        for i in range(1, n):
            mins.append(min(nums[i], mins[-1]))
        for i in range(n - 1, -1, -1):
            if nums[i] > mins[i]:
                while stack and stack[-1] <= mins[i]:
                    stack.pop()
                if stack and stack[-1] < nums[i]:
                    return True
                stack.append(nums[i])
        return False

# @lc code=end
