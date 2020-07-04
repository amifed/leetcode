/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  //中心扩展法
  int expandAroundCenter(string s, int l, int r) {
    while (l > -1 && r < s.length() && s[l] == s[r])
      l--, r++;
    return r - l - 1;
  }
  string longestPalindrome(string s) {
    int pos = 0, max_len = 0;
    for (int i = 0; i < s.length(); i++) {
      int len =
          max(expandAroundCenter(s, i, i), expandAroundCenter(s, i, i + 1));
      if (len > max_len)
        pos = i, max_len = len;
    }
    return s.substr(pos - (max_len - 1) / 2, max_len);
  }
};
// @lc code=end
