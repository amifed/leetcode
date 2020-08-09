/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool check(string &s, int len, int start, int end, unordered_map<string, int> &words) {
        unordered_map<string, int> mp;
        for (int i = 0; i <= (end - start) / len; i++) {
            string sub = s.substr(start + i * len, len);
            if (words.find(sub) == words.end()) {
                return false;
            }
            mp[sub]++;
            if (mp[sub] > words[sub]) {
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> ret;
        if (words.size() == 0) return ret;
        int size = words.size(), len = words[0].length();
        int n = size * len;
        unordered_map<string, int> mp;
        int asc = 0;
        for (auto x : words) {
            mp[x]++;
            for (auto c : x) {
                asc += c;
            }
        }
        int start = 0, end = 0;
        int ascii = 0;
        while (end < s.length()) {
            if (end - start + 1 < n) {
                ascii += s[end];
                end++;
            } else {
                if (ascii + s[end] == asc && check(s, len, start, end, mp)) {
                    ret.push_back(start);
                }
                ascii -= s[start];
                start++;
            }
        }
        return ret;
    }
};
// @lc code=end