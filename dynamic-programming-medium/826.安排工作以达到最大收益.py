#
# @lc app=leetcode.cn id=826 lang=python3
#
# [826] 安排工作以达到最大收益
#
from typing import List


# @lc code=start
class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = list(zip(difficulty, profit))
        jobs.sort()
        ret = i = best = 0
        for skill in sorted(worker):
            while i < len(jobs) and skill >= jobs[i][0]:
                best = max(best, jobs[i][1])
                i += 1
            ret += best
        return ret
# @lc code=end
