#
# @lc app=leetcode.cn id=1342 lang=python3
#
# [1342] 将数字变成 0 的操作次数
#

# @lc code=start
class Solution:
    def numberOfSteps(self, num: int) -> int:
        # 位运算
        # ret = 0
        # while num:
        #     ret += (num & 1) + (num > 1)
        #     num >>= 1
        # return ret

        # 库函数
        # return num.bit_length() + bin(num).count('1') - 1
        
        # 递归
        return sum([num & 1, num > 1, self.numberOfSteps(num >> 1)]) if num else 0


# @lc code=end
Solution().numberOfSteps(14)
