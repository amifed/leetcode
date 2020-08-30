/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool match(string &s, string &p) {
        int i = 0, j = 0;
        while (i < s.length() && j < p.length()) {
            if (s[i] == p[j])
                j++;
            else if (isupper(s[i]))
                return false;
            i++;
        }
        while (i < s.length()) {
            if (isupper(s[i++])) return false;
        }
        return j == p.length();
    }
    vector<bool> camelMatch(vector<string> &qs, string p) {
        vector<bool> ans;
        for (auto &q : qs) {
            ans.push_back(match(q, p));
        }
        return ans;
    }
};
// @lc code=end