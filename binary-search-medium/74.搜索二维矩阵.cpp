/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = matrix.size(), col = matrix.size() == 0 ? 0 : matrix[0].size();
        if (row == 0 || col == 0) return false;
        int left = 0, right = row * col - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int x = mid / col, y = mid % col;
            if (matrix[x][y] < target)
                left = mid + 1;
            else if (matrix[x][y] > target)
                right = mid - 1;
            else
                return true;
        }
        return false;
    };
};
// @lc code=end
