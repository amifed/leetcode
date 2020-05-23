/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0, ret = 0;
    while (i < g.size() && j < s.size()) {
      if (s[j] >= g[i])
        i++, j++, ret++;
      else
        j++;
    }
    return ret;
  }
};
// @lc code=end
