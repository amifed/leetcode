#
# @lc app=leetcode.cn id=1317 lang=python3
#
# [1317] 将整数转换为两个无零整数的和
#
from typing import List


# @lc code=start
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1, n):
            if '0' not in str(i) and '0' not in str(n-i):
                return [i, n-i]
        return []
# @lc code=end
