#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
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
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        queue = collections.deque()
        queue.append(root.left)
        queue.append(root.right)
        while queue:
            p: TreeNode = queue.popleft()
            q: TreeNode = queue.popleft()
            if not p and not q:
                continue
            if not p or not q or p.val != q.val:
                return False
            queue.append(p.left)
            queue.append(q.right)
            queue.append(p.right)
            queue.append(q.left)
        return True

# @lc code=end
