/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }
        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [&](const pair<char, int> &a, const pair<char, int> &b) {
            return a.second != b.second ? a.second > b.second : a.first < b.first;
        });
        string ret;
        for (auto p : v) {
            for (int i = 0; i < p.second; i++) {
                ret.push_back(p.first);
            }
        }
        return ret;
    }
};
// @lc code=end
