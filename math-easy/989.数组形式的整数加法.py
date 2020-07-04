#
# @lc app=leetcode.cn id=989 lang=python3
#
# [989] 数组形式的整数加法
#

# @lc code=start
class Solution:
    def addToArrayForm(self, A: list, K: int) -> list:
        carry = 0
        A.reverse()
        for i in range(len(A)):
            A[i] += carry + K % 10
            carry = A[i] // 10
            A[i] %= 10
            K = K // 10
        while K > 0:
            A.append(carry + K % 10)
            carry = A[len(A) - 1] // 10
            A[len(A) - 1] %= 10
            K = K//10
        if carry > 0:
            A.append(carry)
        A.reverse()
        return A
        # return [int(i) for i in list(str(int(''.join([str(i) for i in A])) + K))]


# @lc code=end
Solution().addToArrayForm([7], 993)
