#
# @lc app=leetcode.cn id=785 lang=python3
#
# [785] 判断二分图
#
import collections
from typing import List


# @lc code=start
class Solution:
    #  DFS
    def isBipartite(self, graph: List[List[int]]) -> bool:
        colors = [set(), set()]

        def dfs(node: int, color: int):
            ret = True
            for i in graph[node]:
                if i in colors[color]:
                    return False
                if i in colors[0] or i in colors[1]:
                    continue
                colors[color ^ 1].add(i)
                if not dfs(i, color ^ 1):
                    ret = False
            return ret

        for n in range(len(graph)):
            if n not in colors[0] and n not in colors[1] and not dfs(n, 0):
                return False
        return True

    # BFS
    # def isBipartite(self, graph: List[List[int]]) -> bool:
    #     A, B = set(), set()
    #     for n in range(len(graph)):
    #         if n in A or n in B:
    #             continue
    #         queue = collections.deque()
    #         queue.append((n, 'A'))
    #         while queue:
    #             node = queue.popleft()
    #             for i in graph[node[0]]:
    #                 if (node[1] == 'A' and i in A) or (node[1] == 'B' and i in B):
    #                     return False
    #                 if i in A or i in B:
    #                     continue
    #                 if node[1] == 'A':
    #                     queue.append((i, 'B'))
    #                     B.add(i)
    #                 else:
    #                     queue.append((i, 'A'))
    #                     A.add(i)
    #     return True
# @lc code=end
