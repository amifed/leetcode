#
# @lc app=leetcode.cn id=174 lang=python3
#
# [174] 地下城游戏
#
import functools
from typing import List


# @lc code=start
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])

        @functools.lru_cache(None)
        def dfs(x: int, y: int) -> int:
            if x == m - 1 and y == n - 1:
                return max(1-dungeon[x][y], 1)
            elif x == m - 1 or y == n - 1:
                return max(dfs(min(m-1, x+1), min(n-1, y+1))-dungeon[x][y], 1)
            return max(min(dfs(x+1, y), dfs(x, y+1)) - dungeon[x][y], 1)

        return dfs(0, 0)
# @lc code=end
