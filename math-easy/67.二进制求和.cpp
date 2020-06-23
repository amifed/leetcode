/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.length(), b.length()), carry = 0;
        for (int i = 0; i < n; i++) {
            carry += i < a.length() ? (a[i] == '1') : 0;
            carry += i < b.length() ? (b[i] == '1') : 0;
            ret.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }
        if (carry)
            ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end
