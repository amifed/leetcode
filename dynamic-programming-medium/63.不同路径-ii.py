#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#
from typing import List


# @lc code=start
class Solution:
    # def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
    #     n, m = len(obstacleGrid), len(obstacleGrid[0])
    #     dp = [[0] * m for _ in range(n)]
    #     for i in range(n):
    #         if obstacleGrid[i][0] == 1:
    #             break
    #         dp[i][0] = 1
    #     for i in range(m):
    #         if obstacleGrid[0][i] == 1:
    #             break
    #         dp[0][i] = 1
    #     for i in range(1, n):
    #         for j in range(1, m):
    #             dp[i][j] = dp[i-1][j] + \
    #                 dp[i][j-1] if obstacleGrid[i][j] == 0 else 0

    #     return dp[-1][-1]

    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n, m = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    if i == 0 and j == 0:
                        dp[i][j] = 1
                    elif i == 0:
                        dp[i][j] = dp[i][j-1]
                    elif j == 0:
                        dp[i][j] = dp[i-1][j]
                    else:
                        dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[-1][-1]
# @lc code=end
