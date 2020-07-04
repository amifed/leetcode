#
# @lc app=leetcode.cn id=394 lang=python3
#
# [394] 字符串解码
#

# @lc code=start
class Solution:
    def decodeString(self, s: str) -> str:
        stack, ret, multi = [], "", 0
        for c in s:
            if '0' <= c <= '9':
                multi = multi*10+int(c)
            elif c == '[':
                stack.append([multi, ret])
                ret, multi = "", 0
            elif c == ']':
                [cur_multi, pre_ret] = stack.pop()
                ret = pre_ret + ret * cur_multi
            else:
                ret += c
        return ret
# @lc code=end
