#
# @lc app=leetcode.cn id=718 lang=python3
#
# [718] 最长重复子数组
#
from typing import List


# @lc code=start
class Solution:
    # Rabin-Karp algorithm
    def findLength(self, A: List[int], B: List[int]) -> int:
        base, mod = 113, 10**9 + 9

        def rabin_karp_check(length: int) -> bool:
            hashA = 0
            for i in range(length):
                hashA = (hashA * base + A[i]) % mod
            bucketA = {hashA}
            mult = pow(base, length-1, mod)  # R^(len-1) % mod
            for i in range(length, len(A)):
                # x(i+1) = [x(i) - t(i)*R^(M-1)]*R + t(i+M)*R^0
                hashA = (((hashA - A[i-length]*mult))*base + A[i]) % mod
                bucketA.add(hashA)

            hashB = 0
            for i in range(length):
                hashB = (hashB * base + B[i]) % mod
            if hashB in bucketA:
                return True
            for i in range(length, len(B)):
                hashB = (((hashB - B[i-length]*mult))*base + B[i]) % mod
                if hashB in bucketA:
                    return True
            return False

        left, right = 0, min(len(A), len(B))
        ret = 0
        while left <= right:
            mid = left + (right - left) // 2
            if rabin_karp_check(mid):
                ret = mid
                left = mid + 1
            else:
                right = mid - 1
        return ret

# @lc code=end
