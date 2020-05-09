/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, int> v_s, v_t;
    for (int i = 0; i < s.length(); i++) {
      if (v_s[s[i]] != v_t[t[i]])
        return false;
      else {
        if (v_s[s[i]] == 0) v_s[s[i]] = i + 1, v_t[t[i]] = i + 1;
      }
    }
    return true;
  }
};
// @lc code=end
// "paper"\n"title"
// "aba"\n"baa"