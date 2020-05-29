#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#
from typing import List


# @lc code=start
class UnionFind:
    def __init__(self, grid: List[List[str]]):
        row, col = len(grid), len(grid[0])
        self.count = 0
        self.parent = [-1] * (row * col)
        self.rank = [0] * (row * col)
        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1':
                    self.parent[i * col + j] = i * col + j
                    self.count += 1

    def find(self, i: int) -> int:
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, x: int, y: int):
        rootx = self.find(x)
        rooty = self.find(y)
        if rootx != rooty:
            if self.rank[rootx] < self.rank[rooty]:
                rootx, rooty = rooty, rootx
            self.parent[rooty] = rootx
            if self.rank[rootx] == self.rank[rooty]:
                self.rank[rootx] += 1
            self.count -= 1


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0
        uf = UnionFind(grid)
        row, col = len(grid), len(grid[0])
        for i in range(row):
            for j in range(col):
                if grid[i][j] == '0':
                    continue
                grid[i][j] = '0'
                for x, y in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                    if -1 < x < row and -1 < y < col and grid[x][y] == '1':
                        uf.union(i * col + j, x * col + y)

        return uf.count
# @lc code=end
