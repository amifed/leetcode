#
# @lc app=leetcode.cn id=297 lang=python3
#
# [297] 二叉树的序列化与反序列化
#
import collections


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return '[]'
        ret = list()
        queue = collections.deque()
        queue.append(root)
        while queue:
            node = queue.popleft()
            if node:
                ret.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
            else:
                ret.append('None')
        return '[' + ','.join(ret) + ']'

    def deserialize(self, data: str):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if data == '[]':
            return None
        vals, index = data[1:-1].split(','), 1
        root = TreeNode(vals[0])
        queue = collections.deque()
        queue.append(root)
        while queue:
            node: TreeNode = queue.popleft()
            if vals[index] != 'None':
                node.left = TreeNode(int(vals[index]))
                queue.append(node.left)
            index += 1
            if vals[index] != 'None':
                node.right = TreeNode(int(vals[index]))
                queue.append(node.right)
            index += 1
        return root
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
# @lc code=end
