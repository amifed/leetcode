#
# @lc app=leetcode.cn id=797 lang=python3
#
# [797] 所有可能的路径
#
from typing import List


# @lc code=start
class Solution:
    def __init__(self):
        self.ret = list()

    def dfs(self, graph: List[List[int]], track: List[int], index: int):
        if index + 1 == len(graph):
            self.ret.append(track[:])
            return
        for i in graph[index]:
            track.append(i)
            self.dfs(graph, track, i)
            track.pop()

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.dfs(graph, [0], 0)
        return self.ret


# @lc code=end
Solution().allPathsSourceTarget([[1, 2], [3], [3], []])
