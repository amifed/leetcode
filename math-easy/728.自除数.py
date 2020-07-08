#
# @lc app=leetcode.cn id=728 lang=python3
#
# [728] 自除数
#
from typing import List


# @lc code=start
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ret = list()
        for i in range(left, right+1):
            s = str(i)
            for c in s:
                if c == '0' or i % int(c) != 0:
                    break
            else:
                ret.append(i)
        return ret
# @lc code=end
