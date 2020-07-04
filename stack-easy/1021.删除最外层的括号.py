#
# @lc app=leetcode.cn id=1021 lang=python3
#
# [1021] 删除最外层的括号
#

# @lc code=start
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        stack, ret = list(), str()
        for i, c in enumerate(S):
            if c == '(':
                stack.append(i)
            else:
                start = stack.pop()
                if not stack:
                    ret += S[start+1:i]
        return ret
# @lc code=end
