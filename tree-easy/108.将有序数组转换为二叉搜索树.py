#
# @lc app=leetcode.cn id=108 lang=python3
#
# [108] 将有序数组转换为二叉搜索树
#
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # list slice
    # def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
    #     if not nums:
    #         return None
    #     n = len(nums)
    #     root = TreeNode(nums[n//2])
    #     root.left = self.sortedArrayToBST(nums[:n//2])
    #     root.right = self.sortedArrayToBST(nums[n//2+1:])
    #     return root

    # index
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:

        def generate(start: int, end: int) -> TreeNode:
            if start > end:
                return None
            mid = (start + end) // 2
            root = TreeNode(nums[mid])
            root.left = generate(start, mid - 1)
            root.right = generate(mid + 1, end)
            return root

        return generate(0, len(nums)-1)


# @lc code=end
