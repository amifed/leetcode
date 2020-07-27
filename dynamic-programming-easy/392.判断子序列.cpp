/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> f(n + 1, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            f[n][i] = n;
        }
        for (int i = n - 1; i > -1; i--) {
            for (int j = 0; j < 26; j++) {
                if (t[i] == j + 'a') {
                    f[i][j] = i;
                } else {
                    f[i][j] = f[i + 1][j];
                }
            }
        }
        int step = 0;
        for (int i = 0; i < m; i++) {
            if (f[step][s[i] - 'a'] == n) {
                return false;
            }
            step = f[step][s[i] - 'a'] + 1;
        }
        return true;
    }
};
// @lc code=end
