#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#

# @lc code=start
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

    def quick_select(l: int, r: int, index: int) -> int:
        pivot_pos = partition(l, r)
        if pivot_pos == index:
            return nums[pivot_pos]
        else:
            return quick_select(pivot_pos+1, r, index) if pivot_pos < index else quick_select(l, pivot_pos-1, index)

    def partition(left: int, right: int) -> int:
        pivot_pos = random.randrange(left, right+1)
        nums[left], nums[pivot_pos] = nums[pivot_pos], nums[left]
        pivot = nums[left]
        while left < right:
            while left < right and nums[right] >= pivot:
                right -= 1
            nums[left] = nums[right]
            while left < right and nums[left] <= pivot:
                left += 1
            nums[right] = nums[left]
        nums[left] = pivot
        return left

    return quick_select(0, len(nums)-1, len(nums) - k)
# @lc code=end
