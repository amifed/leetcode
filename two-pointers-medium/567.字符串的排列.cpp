/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool matches(int s1map[], int s2map[]) {
    for (int i = 0; i < 26; i++)
      if (s1map[i] != s2map[i]) return false;
    return true;
  }
  bool checkInclusion(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();
    if (len1 > len2) return false;
    int s1map[26] = {0}, s2map[26] = {0};
    for (int i = 0; i < len1; i++) s1map[s1[i] - 'a']++, s2map[s2[i] - 'a']++;
    for (int i = 0; i < len2 - len1; i++) {
      if (matches(s1map, s2map)) return true;
      s2map[s2[i + len1] - 'a']++;
      s2map[s2[i] - 'a']--;
    }
    return matches(s1map, s2map);
  }
};
// @lc code=end
