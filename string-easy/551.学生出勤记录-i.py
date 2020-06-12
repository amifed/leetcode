#
# @lc app=leetcode.cn id=551 lang=python3
#
# [551] 学生出勤记录 I
#
import collections


# @lc code=start
class Solution:
    def checkRecord(self, s: str) -> bool:
        cnt = 0
        for i in range(len(s)):
            if s[i] == 'A':
                cnt += 1
            if cnt > 1 or (i < len(s) - 2 and s[i] == s[i+1] == s[i+2] == 'L'):
                return False
        return True

# @lc code=end
