/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[j] = f[j] + f[j - 1];
            }
        }
        return f[n - 1];
    }
};
// @lc code=end

