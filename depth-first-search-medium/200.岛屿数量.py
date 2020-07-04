#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#
from typing import List


# @lc code=start
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0
        row, col = len(grid), len(grid[0])
        return sum([self.dfs(grid, row, col, i, j) for i in range(row) for j in range(col) if grid[i][j] == '1'])

    def dfs(self, grid, row, col, x, y) -> int:
        if x < 0 or x >= row or y < 0 or y >= col or grid[x][y] == '0':
            return 0
        grid[x][y] = '0'
        for i, j in (x-1, y), (x+1, y), (x, y-1), (x, y+1):
            self.dfs(grid, row, col, i, j)
        return 1

# @lc code=end
