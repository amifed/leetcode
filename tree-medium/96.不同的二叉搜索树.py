#
# @lc app=leetcode.cn id=96 lang=python3
#
# [96] 不同的二叉搜索树
#
import functools


# @lc code=start
class Solution:
    @functools.lru_cache
    def numTrees(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        cnt = 0
        for i in range(1, n+1):
            cnt += self.numTrees(i - 1) * self.numTrees(n - i)
        return cnt
# @lc code=end
