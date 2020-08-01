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
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int ret = INT_MIN;
        for (int left = 0; left < col; left++) {
            vector<int> f(row, 0);
            for (int right = left; right < col; right++) {
                int prefixSum = 0;
                multiset<int> ms;
                for (int i = 0; i < row; i++) {
                    f[i] += matrix[i][right];
                    ms.insert(prefixSum);
                    prefixSum += f[i];
                    auto low = ms.lower_bound(prefixSum - k);
                    if (low != ms.end() && prefixSum - *low > ret) {
                        ret = prefixSum - *low;
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end
