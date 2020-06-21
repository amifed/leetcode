#
# @lc app=leetcode.cn id=10 lang=python3
#
# [10] 正则表达式匹配
#

# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:

        @lru_cache(None)
        def recursion(i: int, j: int) -> bool:
            if j == len(p):
                return i == len(s)
            first_match = (len(s) > i) and (p[j] == s[i] or p[j] == '.')
            if len(p) > j+1 and p[j+1] == '*':
                return recursion(i, j+2) or (first_match and recursion(i+1, j))
            return first_match and recursion(i+1, j+1)

        return recursion(0, 0)

# @lc code=end
