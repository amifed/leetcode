#
# @lc app=leetcode.cn id=1106 lang=python3
#
# [1106] 解析布尔表达式
#
from typing import List


# @lc code=start
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stack_op, stack_ch = list(), list()
        for i in expression:
            if i == '!' or i == '|' or i == '&':  # 操作符入栈 stack_op
                stack_op.append(i)
            elif i == ')':  # 出栈计算
                bools = list()  # 使用 List[bool] 记录
                while stack_ch[-1] != '(':
                    if stack_ch[-1] == 't':
                        bools.append(True)
                    if stack_ch[-1] == 'f':
                        bools.append(False)
                    stack_ch.pop()
                stack_ch.pop()  # 将 '(' 出栈
                op = stack_op.pop()  # 操作符出栈
                if op == '!':  # 计算并将结果入栈
                    stack_ch.append('t' if not bools[-1] else 'f')
                elif op == '|':
                    stack_ch.append('t' if any(bools) else 'f')
                elif op == '&':
                    stack_ch.append('t' if all(bools) else 'f')
            else:
                stack_ch.append(i)
        return stack_ch[-1] == 't'


# @lc code=end
Solution().parseBoolExpr("!(f)")
