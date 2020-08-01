/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    //  dp
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> f(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int ret = INT_MIN;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                for (int p = i; p <= row; p++) {
                    for (int q = j; q <= col; q++) {
                        int sum = f[p][q] - f[i - 1][q] - f[p][j - 1] + f[i - 1][j - 1];
                        if (sum > ret && sum <= k) ret = sum;
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end
