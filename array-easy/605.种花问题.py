#
# @lc app=leetcode.cn id=605 lang=python3
#
# [605] 种花问题
#
from typing import List


# @lc code=start
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        for i in range(len(flowerbed)):
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i-1] == 0) and (i + 1 == len(flowerbed) or flowerbed[i+1] == 0):
                flowerbed[i] = 1
                n -= 1
        return n <= 0
# @lc code=end
