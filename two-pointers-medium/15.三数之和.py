#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#
from typing import List


# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ret = list()
        for i in range(len(nums) - 2):
            if i > 0 and nums[i-1] == nums[i]:
                continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                num_sum = nums[i] + nums[l] + nums[r]
                if num_sum < 0:
                    l += 1
                elif num_sum > 0:
                    r -= 1
                else:
                    ret.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l+1]:
                        l += 1
                    while l < r and nums[r-1] == nums[r]:
                        r -= 1
                    l += 1
                    r -= 1
        return ret


# @lc code=end
Solution().threeSum([-1, 0, 1, 2, -1, -4])
