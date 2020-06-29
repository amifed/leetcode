#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#
from typing import List


# @lc code=start
class Solution:

    def findKthLargest(self, nums: List[int], k: int) -> int:

        def max_heapify(i: int, heap_size: int):
            l, r, largest = i*2+1, i*2+2, i
            if l < heap_size and nums[l] > nums[largest]:
                largest = l
            if r < heap_size and nums[r] > nums[largest]:
                largest = r
            if largest != i:
                nums[i], nums[largest] = nums[largest], nums[i]
                max_heapify(largest, heap_size)

        def build_max_heap(heap_size: int):
            for i in range(heap_size//2, -1, -1):
                max_heapify(i, heap_size)

        heap_size = len(nums)
        build_max_heap(heap_size)
        for i in range(len(nums)-1, len(nums) - k, -1):
            nums[0], nums[i] = nums[i], nums[0]
            heap_size -= 1
            max_heapify(0, heap_size)
        return nums[0]


# @lc code=end
print(Solution().findKthLargest([3, 2, 3, 1, 2, 4, 5, 5, 6], 4))
