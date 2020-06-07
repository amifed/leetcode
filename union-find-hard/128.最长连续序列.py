#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#
from typing import List


# @lc code=start
class UnionFind:
    def __init__(self, nums: List[int]):
        self.parent = [i for i in range(len(nums))]
        self.count = [1] * len(nums)

    # 路径压缩
    def find(self, i: int) -> int:
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, x: int, y: int):
        rootx, rooty = self.find(x), self.find(y)
        if rootx != rooty:
            self.parent[rootx] = rooty
            self.count[rooty] += self.count[rootx]
        return self.count[rooty]


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        uf = UnionFind(nums)
        record, ret = dict(), 1
        for i, num in enumerate(nums):
            if num in record:
                continue
            record[num] = i
            if num + 1 in record:
                ret = max(ret, uf.union(i, record[num + 1]))
            if num - 1 in record:
                ret = max(ret, uf.union(record[num - 1], i))
        return ret
# @lc code=end
