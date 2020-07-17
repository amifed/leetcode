#
# @lc app=leetcode.cn id=944 lang=python3
#
# [944] 删列造序
#
from typing import List


# @lc code=start
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        ret = 0
        for i in range(len(A[0])):
            for j in range(1, len(A)):
                if (ord(A[j][i]) < ord(A[j-1][i])):
                    ret += 1
                    break
        return ret
# @lc code=end
