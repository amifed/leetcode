#
# @lc app=leetcode.cn id=238 lang=python3
#
# [238] 除自身以外数组的乘积
#
from typing import List


# @lc code=start
class Solution:
    # 前缀积 + 后缀积
    # def productExceptSelf(self, nums: List[int]) -> List[int]:
    #     left, right, n = list([1]), list([1]), len(nums)
    #     for i in range(1, n):
    #         left.append(nums[i - 1] * left[i - 1])
    #     for i in reversed(range(n - 1)):
    #         right.insert(0, right[0] * nums[i + 1])
    #     return [left[i] * right[i] for i in range(n)]
    # 前缀积 O(1)
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n, ret = len(nums), list([1])
        for i in range(1, n):
            ret.append(nums[i - 1] * ret[i - 1])
        right = 1
        for i in reversed(range(n)):
            ret[i] *= right
            right *= nums[i]
        return ret
# @lc code=end
