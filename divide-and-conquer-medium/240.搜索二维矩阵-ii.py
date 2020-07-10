#
# @lc app=leetcode.cn id=240 lang=python3
#
# [240] 搜索二维矩阵 II
#

# @lc code=start
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        def search(left, up, right, down):
            if left > right or up > down:
                return False
            elif target < matrix[up][left] or matrix[down][right] < target:
                return False
            mid = left + (right - left) // 2
            row = up
            while row <= down and matrix[row][mid] <= target:
                if matrix[row][mid] == target:
                    return True
                row += 1
            return search(left, row, mid-1, down) or search(mid+1, up, right, row-1)

        if not matrix:
            return False
        return search(0, 0, len(matrix[0])-1, len(matrix)-1)
# @lc code=end
