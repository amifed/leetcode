/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = matrix.size(), col = matrix.size() > 0 ? matrix[0].size() : 0;
        if (row == 0 || col == 0) {
            return false;
        }
        int x = 0, y = col - 1;
        while (x < row && y > -1) {
            if (matrix[x][y] < target) {
                x++;
            } else if (matrix[x][y] > target) {
                y--;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
