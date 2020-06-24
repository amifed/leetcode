#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#
from typing import List


# @lc code=start
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ret = nums[0] + nums[1] + nums[2]
        for i in range(len(nums) - 2):
            l, r = i+1, len(nums)-1
            while l < r:
                num_sum = nums[i] + nums[l] + nums[r]
                if abs(ret - target) > abs(num_sum - target):
                    ret = num_sum
                if num_sum < target:
                    l += 1
                elif num_sum > target:
                    r -= 1
                else:
                    return target
        return ret


# @lc code=end
Solution().threeSumClosest([-3, -2, -5, 3, -4], -1)
