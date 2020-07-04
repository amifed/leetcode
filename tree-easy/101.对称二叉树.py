#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#
# Definition for a binary tree node.
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
    def helper(self, root1: TreeNode, root2: TreeNode) -> bool:
        if not root1 and not root2:
            return True
        elif not root1 or not root2:
            return False
        return root1.val == root2.val and self.helper(root1.left, root2.right) and self.helper(root1.right, root2.left)

    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        return self.helper(root.left, root.right)


# @lc code=end
