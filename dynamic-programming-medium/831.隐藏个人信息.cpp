/*
 * @lc app=leetcode.cn id=831 lang=cpp
 *
 * [831] 隐藏个人信息
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  string email(string s) {
    int pos = s.find('@');
    for (int i = pos; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }
    string ret;
    ret.push_back(tolower(s[0]));
    ret.append("*****");
    ret.push_back(tolower(s[pos - 1]));
    ret.append(s.substr(pos));
    return ret;
  }
  string phone(string &s) {
    int cnt = 0;
    for (auto &&c : s)
      if (isalnum(c))
        cnt++;
    string ret;
    for (int i = 0; i < 4;) {
      if (isalnum(s.back())) {
        ret.push_back(s.back());
        i++;
      }
      s.pop_back();
    }
    ret.append("-***-***");
    if (cnt > 10) {
      ret.push_back('-');
      for (int i = 0; i < cnt - 10; i++) {
        ret.push_back('*');
      }
      ret.push_back('+');
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
  string maskPII(string S) {
    if (S.find('@') != S.npos)
      return email(S);
    else
      return phone(S);
  }
};
// @lc code=end
