#
# @lc app=leetcode.cn id=130 lang=python3
#
# [130] 被围绕的区域
#
from typing import List


# @lc code=start
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row, col = len(board), 0 if len(board) == 0 else len(board[0])

        def dfs(r: int, c: int) -> None:
            board[r][c] = '#'
            for i, j in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
                x, y = r + i, c + j
                if -1 < x < row and -1 < y < col and board[x][y] == 'O':
                    board[x][y] = '#'
                    dfs(x, y)

        for i in range(0, row):
            if board[i][0] == 'O':
                dfs(i, 0)
            if board[i][col - 1] == 'O':
                dfs(i, col - 1)

        for j in range(0, col):
            if board[0][j] == 'O':
                dfs(0, j)
            if board[row - 1][j] == 'O':
                dfs(row - 1, j)

        for i in range(0, row):
            for j in range(0, col):
                if board[i][j] == '#':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
# @lc code=end
