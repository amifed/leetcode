/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  bool checkPalindrome(string s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r])
        return false;
      l++, r--;
    }
    return true;
  }
  bool validPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
      if (s[l] == s[r])
        l++, r--;
      else
        return checkPalindrome(s, l + 1, r) || checkPalindrome(s, l, r - 1);
    }
    return true;
  }
};
// @lc code=end