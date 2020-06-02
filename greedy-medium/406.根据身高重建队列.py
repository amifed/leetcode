#
# @lc app=leetcode.cn id=406 lang=python3
#
# [406] 根据身高重建队列
#
from typing import List


# @lc code=start
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda x: [-x[0], x[1]])
        output = list()
        for p in people:
            output.insert(p[1], p)
        return output


# @lc code=end
Solution().reconstructQueue([[9, 0], [7, 0], [1, 9], [3, 0], [
    2, 7], [5, 3], [6, 0], [3, 4], [6, 2], [5, 2]])
