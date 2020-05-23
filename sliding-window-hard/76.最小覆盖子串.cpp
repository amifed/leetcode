/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
  unordered_map<char, int> ums, umt;

public:
  bool check() {
    for (auto &&m : umt) {
      if (ums[m.first] < m.second)
        return false;
    }
    return true;
  }
  string minWindow(string s, string t) {
    for (auto &&c : t)
      umt[c]++;
    int l = 0, r = -1;
    int len = INT_MAX, start = -1;
    while (r < int(s.size())) {
      if (umt.find(s[++r]) != umt.end())
        ums[s[r]]++;
      while (check() && l <= r) {
        if (r - l + 1 < len) {
          len = r - l + 1;
          start = l;
        }
        if (ums.find(s[l]) != ums.end())
          ums[s[l]]--;
        l++;
      }
    }
    return start == -1 ? string() : s.substr(start, len);
  }
};
// @lc code=end
