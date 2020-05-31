#
# @lc app=leetcode.cn id=1305 lang=python3
#
# [1305] 两棵二叉搜索树中的所有元素
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
    # 归并排序
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def inorder(root: TreeNode, path: List[int]):
            if root:
                inorder(root.left, path)
                path.append(root.val)
                inorder(root.right, path)
        path1,  path2 = list(), list()
        inorder(root1, path1)
        inorder(root2, path2)
        i, j, len1, len2, ret = 0, 0, len(path1), len(path2), list()
        while i < len1 and j < len2:
            if path1[i] <= path2[j]:
                ret.append(path1[i])
                i += 1
            else:
                ret.append(path2[j])
                j += 1
        ret.extend(path1[i:])
        ret.extend(path2[j:])
        return ret
# @lc code=end
