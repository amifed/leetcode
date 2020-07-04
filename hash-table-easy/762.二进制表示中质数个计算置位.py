#
# @lc app=leetcode.cn id=762 lang=python3
#
# [762] 二进制表示中质数个计算置位
#

# @lc code=start
class Solution:
    def countPrimeSetBits(self, L: int, R: int) -> int:
        return sum(bin(x).count('1') in {2, 3, 5, 7, 11, 13, 17, 19} for x in range(L, R+1))
# @lc code=end
