#
# @lc app=leetcode.cn id=394 lang=python3
#
# [394] 字符串解码
#

# @lc code=start
class Solution:
    def decodeString(self, s: str) -> str:
        def dfs(s, i) -> str:
            ret, multi = "", 0
            while i < len(s):
                if '0' <= s[i] <= '9':
                    multi = multi*10 + int(s[i])
                elif s[i] == '[':
                    i, temp = dfs(s, i+1)
                    ret += temp*multi
                    multi = 0
                elif s[i] == ']':
                    return i, ret
                else:
                    ret += s[i]
                i += 1
            return ret
        return dfs(s, 0)
# @lc code=end
