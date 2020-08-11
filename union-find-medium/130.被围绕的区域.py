#
# @lc app=leetcode.cn id=130 lang=python3
#
# [130] 被围绕的区域
#
from typing import List


# @lc code=start
class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n
        self.count = n

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int):
        rootx, rooty = self.find(x), self.find(y)
        if rootx != rooty:
            if self.rank[rootx] > self.rank[rooty]:
                rootx, rooty = rooty, rootx
            self.parent[rootx] = rooty
            if self.rank[rootx] == self.rank[rooty]:
                self.rank[y] += 1
            self.count -= 1


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        row, col = len(board), 0 if len(board) == 0 else len(board[0])
        if row == 0 or col == 0:
            return

        def node(i: int, j: int) -> int:
            return i * col + j

        uf = UnionFind(row * col + 1)
        dummy = row * col
        for i in range(0, row):
            for j in range(0, col):
                if board[i][j] != 'O':
                    continue
                if i == 0 or i == row - 1 or j == 0 or j == col - 1:
                    uf.union(node(i, j), dummy)
                else:
                    for r, c in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
                        x, y = r + i, c + j
                        if -1 < x < row and -1 < y < col and board[x][y] == 'O':
                            uf.union(node(i, j), node(x, y))

        for i in range(0, row):
            for j in range(0, col):
                if board[i][j] == 'O' and uf.find(node(i, j)) != uf.find(dummy):
                    board[i][j] = 'X'
# @lc code=end
