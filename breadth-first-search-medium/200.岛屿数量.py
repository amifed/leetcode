#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#
from typing import List
import collections


# @lc code=start
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0
        row, col = len(grid), len(grid[0])
        return sum([self.bfs(grid, row, col, i, j) for i in range(row) for j in range(col) if grid[i][j] == '1'])

    def bfs(self, grid, row, col, _x, _y) -> int:
        grid[_x][_y] = '0'
        queue = collections.deque([(_x, _y)])
        while queue:
            i, j = queue.popleft()
            for x, y in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if -1 < x < row and -1 < y < col and grid[x][y] == '1':
                    grid[x][y] = '0'
                    queue.append((x, y))
        return 1

# @lc code=end
