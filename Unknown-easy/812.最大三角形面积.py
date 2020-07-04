#
# @lc app=leetcode.cn id=812 lang=python3
#
# [812] 最大三角形面积
#
from typing import List
import itertools


# @lc code=start
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        def area(p: List[int], q: List[int], r: List[int]) -> float:
            return abs(p[0] * q[1] + q[0] * r[1] + r[0] * p[1]
                       - p[1] * q[0] - q[1] * r[0] - r[1] * p[0])
        return .5 * max(area(*triangle) for triangle in itertools.combinations(points, 3))

# @lc code=end
