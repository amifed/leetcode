#
# @lc app=leetcode.cn id=112 lang=python3
#
# [112] 路径总和
#
import collections


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
    # def hasPathSum(self, root: TreeNode, sum: int) -> bool:
    #     """sum"""
    #     def dfs(node: TreeNode, path_sum: int) -> bool:
    #         if not node:
    #             return False
    #         elif not node.left and not node.right:
    #             return path_sum + node.val == sum
    #         return dfs(node.left, path_sum + node.val) or dfs(node.right, path_sum + node.val)
    #     return dfs(root, 0)
    # def hasPathSum(self, root: TreeNode, sum: int) -> bool:
    #     """minus"""
    #     if not root:
    #         return False
    #     elif not root.left and not root.right:
    #         return root.val == sum
    #     return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        """bfs"""
        if not root:
            return False
        queue_node = collections.deque([root])
        queue_sum = collections.deque([root.val])
        while queue_node:
            node: TreeNode = queue_node.popleft()
            path_sum = queue_sum.popleft()
            if not node.left and not node.right and path_sum == sum:
                return True
            if node.left:
                queue_node.append(node.left)
                queue_sum.append(path_sum + node.left.val)
            if node.right:
                queue_node.append(node.right)
                queue_sum.append(path_sum + node.right.val)
        return False

# @lc code=end
