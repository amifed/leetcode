/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isSubsequence(string s, string t) {
    auto p = s.begin(), q = t.begin();
    while (p != s.end() && q != t.end()) {
      if (*p == *q)
        q++;
      p++;
    }
    return q == t.end();
  }
  string findLongestWord(string s, vector<string> &d) {
    string ret = "";
    for (auto &&i : d) {
      if (ret.length() > i.length() || (ret.length() == i.length() && ret < i))
        continue;
      if (isSubsequence(s, i))
        ret = i;
    }
    return ret;
  }
};
// @lc code=end
