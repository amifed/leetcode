/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  bool isHuiwen(string str, int s, int e) {
    for (int i = s, j = e; i < j; i++, j--)
      if (str[i] != str[j]) return false;
    return true;
  }
  void backtracking(vector<vector<string>>& ret, vector<string>& track, string s, int index, int len) {
    if (index == len) {
      ret.push_back(track);
      return;
    }
    for (int i = index; i < len; i++) {
      if (!isHuiwen(s, index, i)) continue;
      track.push_back(s.substr(index, i - index + 1));
      backtracking(ret, track, s, i + 1, len);
      track.pop_back();
    }
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ret;
    vector<string> track;
    int len = s.length();
    if (len == 0) return ret;
    backtracking(ret, track, s, 0, len);
    return ret;
  }
};
// @lc code=end
