/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  string countAndSay(int n) {
    string org = "1";
    if (n == 1) return org;
    for (int i = 1; i < n; i++) {
      string t;
      for (int j = 0; j < org.length();) {
        int k = j + 1;
        while (k < org.length() && org[j] == org[k]) k++;
        t.push_back(k - j + '0');
        t.push_back(org[j]);
        j = k;
      }
      org = t;
    }
    return org;
  }
};
// @lc code=end
