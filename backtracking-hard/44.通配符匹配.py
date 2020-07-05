#
# @lc app=leetcode.cn id=44 lang=python3
#
# [44] 通配符匹配
#
import functools


# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:

        @functools.lru_cache(None)
        def backtracking(ptr_s: int, ptr_p: int) -> bool:
            if ptr_s == len(s) and ptr_p == len(p):
                return True

            if ptr_p < len(p) and p[ptr_p] == '*':
                for i in range(ptr_s, len(s)+1):
                    if backtracking(i, ptr_p+1):
                        return True
            elif ptr_s < len(s) and ptr_p < len(p) and (p[ptr_p] == '?' or p[ptr_p] == s[ptr_s]) and backtracking(ptr_s+1, ptr_p+1):
                return True
            return False

        return backtracking(0, 0)


# @lc code=end
