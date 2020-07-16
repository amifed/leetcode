/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<string> ret;
    bool isValid(string s) {
        if (s[0] == '0') return s.length() == 1;
        int num = 0;
        for (auto c : s)
            num = num * 10 + (c - '0');
        return num < 256;
    }
    void backtracking(string &s, vector<string> &track, int index) {
        if (track.size() == 4) {
            if (index == s.length()) {
                ret.push_back(track[0] + "." + track[1] + "." + track[2] + "." + track[3]);
            }
            return;
        }
        if (index > s.length()) return;
        for (int i = 1; i <= 3; i++) {
            string sub = s.substr(index, i);
            if (!isValid(sub)) break;
            track.push_back(sub);
            backtracking(s, track, index + i);
            track.pop_back();
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> track;
        backtracking(s, track, 0);
        return ret;
    }
};
// @lc code=end
