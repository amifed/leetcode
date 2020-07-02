#
# @lc app=leetcode.cn id=504 lang=python3
#
# [504] 七进制数
#

# @lc code=start
class Solution:
    # def convertToBase7(self, num: int) -> str:
    #     """iteration"""
    #     convert = abs(num)
    #     ret = ""
    #     while convert >= 7:
    #         ret += str(convert % 7)
    #         convert //= 7
    #     ret += str(convert)
    #     return ret[::-1] if num >= 0 else '-'+ret[::-1]
    def convertToBase7(self, num: int) -> str:
        """recursive"""
        if num < 0:
            return '-' + self.convertToBase7(-num)
        if num < 7:
            return str(num)
        return self.convertToBase7(num // 7) + str(num % 7)
# @lc code=end
