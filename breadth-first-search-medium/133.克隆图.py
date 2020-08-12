#
# @lc app=leetcode.cn id=133 lang=python3
#
# [133] 克隆图
#
import collections


class Node:
    def __init__(self, val=0, neighbors=[]):
        self.val = val
        self.neighbors = neighbors


# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        queue = collections.deque([node])
        visited = {node: Node(node.val)}
        while queue:
            p = queue.popleft()
            for neighbor in p.neighbors:
                if neighbor not in visited:
                    visited[neighbor] = Node(neighbor.val)
                    queue.append(neighbor)
                visited[p].neighbors.append(visited[neighbor])

        return visited[node]
# @lc code=end
