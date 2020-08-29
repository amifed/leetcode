/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    /*暴力*/
    string shortestPalindrome(string s) {
        int n = s.length();
        string r(s.rbegin(), s.rend());
        for (int i = n; i >= 0; i--) {
            if (s.substr(0, i) == r.substr(n - i, n)) {
                return r.substr(0, n - i) + s;
            }
        }
        return r + s;
    }
    const int base = 127, mod = 1e9 + 7;
    string shortestPalindrome(string s) {
        int n = s.length();
        int left = 0, right = 0, mul = 1;
        int best = -1;
        for (int i = 0; i < n; i++) {
            left = (1LL * left * base + s[i]) % mod;
            right = (right + 1LL * mul * s[i]) % mod;
            mul = 1LL * mul * base % mod;
            if (left == right) {
                best = i;
            }
        }
        string add = best == n - 1 ? "" : s.substr(best + 1, n);
        reverse(add.begin(), add.end());
        return add + s;
    }
};
// @lc code=end
