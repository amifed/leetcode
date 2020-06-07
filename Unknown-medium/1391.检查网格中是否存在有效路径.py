#
# @lc app=leetcode.cn id=1391 lang=python3
#
# [1391] 检查网格中是否存在有效路径
#
import collections
from typing import List


# @lc code=start
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        row, col = len(grid), len(grid[0])
        queue, visited = collections.deque(), set()

        def detectL(x: int, y: int):
            if y - 1 > -1 and (x, y - 1) not in visited and grid[x][y-1] in [1, 4, 6]:
                visited.add((x, y-1))
                queue.append((x, y-1))

        def detectR(x: int, y: int):
            if y + 1 < col and (x, y + 1) not in visited and grid[x][y+1] in [1, 3, 5]:
                visited.add((x, y+1))
                queue.append((x, y+1))

        def detectU(x: int, y: int):
            if x - 1 > -1 and (x - 1, y) not in visited and grid[x-1][y] in [2, 3, 4]:
                visited.add((x-1, y))
                queue.append((x-1, y))

        def detectD(x: int, y: int):
            if x + 1 < row and (x + 1, y) not in visited and grid[x+1][y] in [2, 5, 6]:
                visited.add((x+1, y))
                queue.append((x+1, y))

        queue.append((0, 0))
        visited.add((0, 0))
        while queue:
            x, y = queue.popleft()
            if x == row-1 and y == col-1:
                return True

            if grid[x][y] == 1:
                detectL(x, y)
                detectR(x, y)
            elif grid[x][y] == 2:
                detectU(x, y)
                detectD(x, y)
            elif grid[x][y] == 3:
                detectL(x, y)
                detectD(x, y)
            elif grid[x][y] == 4:
                detectR(x, y)
                detectD(x, y)
            elif grid[x][y] == 5:
                detectL(x, y)
                detectU(x, y)
            else:
                detectR(x, y)
                detectU(x, y)
        return False


# @lc code=end
Solution().hasValidPath([[2, 4, 3], [6, 5, 2]])
