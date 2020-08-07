/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagrams(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int mp[26] = {0}, ms[26] = {0};
        for (auto c : p) {
            mp[c - 'a']++;
        }
        int n = p.length();
        vector<int> ret;
        for (int i = 0; i < s.length(); i++) {
            if (i < n - 1) {
                ms[s[i] - 'a']++;
            } else {
                ms[s[i] - 'a']++;
                if (isAnagrams(ms, mp)) {
                    ret.push_back(i - n + 1);
                }
                ms[s[i - n + 1] - 'a']--;
            }
        }
        return ret;
    }
};
// @lc code=end