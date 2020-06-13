#
# @lc app=leetcode.cn id=116 lang=python3
#
# [116] 填充每个节点的下一个右侧节点指针
#
import collections


class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right 
        self.next = next
"""


class Solution:
    # dfs
    # def connect(self, root: 'Node') -> 'Node':
    #     if not root:
    #         return root

    #     def dfs(left: 'Node', right: 'Node'):
    #         if left:
    #             left.next = right
    #             dfs(left.left, left.right)
    #             dfs(left.right, right.left)
    #             dfs(right.left, right.right)

    #     dfs(root.left, root.right)

    #     return root
    # bfs
    # def connect(self, root: 'Node') -> 'Node':
    #     if not root:
    #         return root
    #     queue = collections.deque()
    #     queue.append(root)
    #     while queue:
    #         size = len(queue)
    #         for i in range(size):
    #             node = queue.popleft()
    #             if i < size - 1:
    #                 node.next = queue[0]
    #             if node.left:
    #                 queue.append(node.left)
    #             if node.right:
    #                 queue.append(node.right)
    #     return root
    # iteration
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        left_most = root
        while left_most.left:
            head = left_most
            while head:
                head.left.next = head.right
                if head.next:
                    head.right.next = head.next.left
                head = head.next
            left_most = left_most.left
        return root
# @lc code=end
