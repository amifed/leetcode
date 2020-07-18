#
# @lc app=leetcode.cn id=726 lang=python3
#
# [726] 原子的数量
#
import collections


# @lc code=start
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        N = len(formula)
        stack = [collections.Counter()]
        i = 0
        while i < N:
            if formula[i] == '(':
                stack.append(collections.Counter())
                i += 1
            elif formula[i] == ')':
                top = stack.pop()
                i += 1
                start = i
                while i < N and formula[i].isdigit():
                    i += 1
                multiple = int(formula[start:i] or 1)
                for k, v in top.most_common():
                    stack[-1][k] += v * multiple
            else:
                start = i
                i += 1
                while i < N and formula[i].islower():
                    i += 1
                key = formula[start: i]
                start = i
                while i < N and formula[i].isdigit():
                    i += 1
                value = int(formula[start: i] or 1)
                stack[-1][key] += value

        return "".join(k + (str(stack[-1][k]) if stack[-1][k] > 1 else '') for k in sorted(stack[-1]))


# @lc code=end
