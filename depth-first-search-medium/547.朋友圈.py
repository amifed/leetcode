#
# @lc app=leetcode.cn id=547 lang=python3
#
# [547] 朋友圈
#
import collections
from typing import List


# @lc code=start
class Solution:
    # dfs
    # def findCircleNum(self, M: List[List[int]]) -> int:
    #     cnt, visited = 0, set()

    #     def dfs(x: int):
    #         for y in range(len(M[x])):
    #             if M[x][y] == 1 and y not in visited:
    #                 visited.add(y)
    #                 dfs(y)

    #     for i in range(len(M)):
    #         if i not in visited:
    #             dfs(i)
    #             cnt += 1
    #     return cnt

    # bfs
    def findCircleNum(self, M: List[List[int]]) -> int:
        cnt, visited = 0, set()

        def bfs(x: int):
            queue = collections.deque()
            queue.append(x)
            while queue:
                i = queue.popleft()
                for j in range(len(M)):
                    if M[i][j] == 1 and j not in visited:
                        visited.add(j)
                        queue.append(j)

        for n in range(len(M)):
            if n not in visited:
                bfs(n)
                cnt += 1

        return cnt

# @lc code=end
