/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool match(string word, string pattern) {
        unordered_map<char, char> m;
        for (int i = 0; i < pattern.size(); i++) {
            if (m.find(pattern[i]) == m.end())
                m[pattern[i]] = word[i];
            else if (m[pattern[i]] != word[i])
                return false;
        }
        unordered_set<char> s;
        for (auto c : m) {
            if (s.find(c.second) != s.end())
                return false;
            s.insert(c.second);
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> ret;
        for (auto word : words)
            if (match(word, pattern))
                ret.push_back(word);
        return ret;
    }
};
// @lc code=end