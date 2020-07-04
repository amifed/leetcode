#
# @lc app=leetcode.cn id=1014 lang=python3
#
# [1014] 最佳观光组合
#

# @lc code=start
class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        ret, max_score = 0, A[0]
        for i in range(1, len(A)):
            ret = max(ret, max_score + A[i] - i)
            max_score = max(max_score, A[i] + i)
        return ret
# @lc code=end
