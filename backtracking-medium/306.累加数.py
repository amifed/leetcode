#
# @lc app=leetcode.cn id=306 lang=python3
#
# [306] 累加数
#

# @lc code=start
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        def add(num1: str, num2: str) -> str:
            two_sum = str()
            m, n = len(num1)-1, len(num2)-1
            carry = 0
            while m > -1 or n > -1 or carry > 0:
                carry += int(num1[m]) if m > -1 else 0
                m -= 1
                carry += int(num2[n]) if n > -1 else 0
                n -= 1
                two_sum += str(carry % 10)
                carry //= 10
            return two_sum[::-1]

        def dfs(i: int, j: int, k: int) -> bool:
            if k == len(num):
                return True
            if (num[i] == '0' and j - i > 1) or (num[j] == '0' and k - j > 1):
                return False
            two_sum = add(num[i:j], num[j:k])
            if two_sum != num[k:k+len(two_sum)]:
                return False
            return dfs(j, k, k+len(two_sum))

        i = 0
        for j in range(i+1, len(num)):
            for k in range(j+1, len(num)):
                if dfs(i, j, k):
                    return True
        return False


# @lc code=end
Solution().isAdditiveNumber('1231')
