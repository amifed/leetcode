/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int expand(string &s, int l, int r) {
        int ret = 0;
        while (l > -1 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
            ret++;
        }
        return ret;
    }
    int countSubstrings(string s) {
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            ret += expand(s, i, i) + expand(s, i, i + 1);
        }
    }
};
// @lc code=end
