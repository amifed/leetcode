#
# @lc app=leetcode.cn id=139 lang=python3
#
# [139] 单词拆分
#
from typing import List


# @lc code=start
class Solution:
    # backtracking
    # def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    #     @lru_cache()
    #     def backtracking(start: int) -> bool:
    #         if start >= len(s):
    #             return True
    #         for end in range(start+1, len(s)+1):
    #             if s[start:end] in wordDict and backtracking(end):
    #                 return True
    #         return False

    #     return backtracking(0)

    # memo
    # def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    #     memo = dict()

    #     def backtracking(start: int) -> bool:
    #         if start >= len(s):
    #             return True
    #         if start in memo:
    #             return memo[start]
    #         for end in range(start+1, len(s)+1):
    #             sub = s[start:end]
    #             if sub in wordDict:
    #                 memo[start] = backtracking(end)
    #                 if memo[start]:
    #                     return True
    #         memo[start] = False
    #         return False

    #     return backtracking(0)


    # dynamic programming
    # def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    #     dp = [False] * (len(s)+1)
    #     dp[0] = True
    #     for i in range(1, len(s)+1):
    #         for j in range(0, i):
    #             if dp[j] and s[j:i] in wordDict:
    #                 dp[i] = True
    #                 break
    #     return dp[-1]
# @lc code=end
print(Solution().wordBreak("aaaaaaa", ["aaaa", "aaa"]))
