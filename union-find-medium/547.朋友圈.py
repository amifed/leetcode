#
# @lc app=leetcode.cn id=547 lang=python3
#
# [547] 朋友圈
#
from typing import List


# @lc code=start
class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n
        self.count = n

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int):
        rootx, rooty = self.find(x), self.find(y)
        if rootx != rooty:
            if self.rank[rootx] > self.rank[rooty]:
                rootx, rooty = rooty, rootx
            self.parent[rootx] = rooty
            if self.rank[rootx] == self.rank[rooty]:
                self.rank[y] += 1
            self.count -= 1


class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        uf = UnionFind(n)
        for i in range(n):
            for j in range(i+1, n):
                if M[i][j] == 1:
                    uf.union(i, j)
        return uf.count
# @lc code=end
