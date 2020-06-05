#
# @lc app=leetcode.cn id=72 lang=python3
#
# [72] 编辑距离
#

# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n, m = len(word1), len(word2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):  # 第 0 列
            dp[i][0] = i
        for j in range(1, m + 1):  # 第 0 行
            dp[0][j] = j
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1])
                else:
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
        return dp[-1][-1]
    # 递归思路
    # def minDistance(self, word1: str, word2: str) -> int:
    #     if not word1 or not word2:
    #         return len(word1) + len(word2)
    #     word1_insert = self.minDistance(word1[1:], word2)
    #     word2_insert = self.minDistance(word1, word2[1:])
    #     word1_word2 = self.minDistance(word1[1:], word2[1:])
    #     if word1[0] == word2[0]:
    #         return min(word1_insert + 1, word2_insert + 1, word1_word2)
    #     else:
    #         return 1 + min(word1_insert, word2_insert, word1_word2)


# @lc code=end
