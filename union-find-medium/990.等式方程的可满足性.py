#
# @lc app=leetcode.cn id=990 lang=python3
#
# [990] 等式方程的可满足性
#
from typing import List


# @lc code=start
class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int):
        # self.parent(self.find(x)) = self.find(y)
        rootx, rooty = self.find(x), self.find(y)
        if rootx != rooty:
            if self.rank[rootx] > self.rank[rooty]:
                rootx, rooty = rooty, rootx
            self.parent[rootx] = rooty
            if self.rank[rootx] == self.rank[rooty]:
                self.rank[y] += 1


class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        uf = UnionFind(26)

        def to_ascii(ch: str) -> int:
            return ord(ch) - ord('a')

        for equation in equations:
            if equation[1] == '=':
                uf.union(to_ascii(equation[0]), to_ascii(equation[-1]))

        for equation in equations:
            if equation[1] == '!' and uf.find(to_ascii(equation[0])) == uf.find(to_ascii(equation[-1])):
                return False
        return True
# @lc code=end
