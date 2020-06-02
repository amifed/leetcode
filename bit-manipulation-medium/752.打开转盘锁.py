#
# @lc app=leetcode.cn id=752 lang=python3
#
# [752] 打开转盘锁
#
from typing import List
import collections


# @lc code=start
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def neighbors(node: str):
            for i in range(4):
                for d in (-1, 1):
                    yield node[:i] + str((int(node[i]) + d) % 10) + node[i+1:]
        dead = set(deadends)
        visited = set({'0000'})
        queue = collections.deque([('0000', 0)])
        while queue:
            node, depth = queue.popleft()
            if node == target:
                return depth
            if node in dead:
                continue
            for i in neighbors(node):
                if i not in visited:
                    visited.add(i)
                    queue.append((i, depth+1))
        return -1
# @lc code=end
