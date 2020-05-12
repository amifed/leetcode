/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  // TLE
  // bool no_common_letters(string s1, string s2) {
  //   int bitmask1 = 0, bitmask2 = 0;
  //   for (auto &&i : s1)
  //     bitmask1 |= 1 << (i - 'a');
  //   for (auto &&i : s2)
  //     bitmask2 |= 1 << (i - 'a');
  //   return (bitmask1 & bitmask2) == 0;
  // }
  // int maxProduct(vector<string> &words) {
  //   int ret = 0, size = words.size();
  //   for (int i = 0; i < size; i++)
  //     for (int j = i + 1; j < size; j++)
  //       if (no_common_letters(words[i], words[j]))
  //         ret = max(ret, (int)words[i].length() * (int)words[j].length());
  //   return ret;
  // }
  int maxProduct(vector<string> &words) {
    int ret = 0, size = words.size();
    vector<int> v(size, 0);
    for (int i = 0; i < size; i++) {
      for (auto &&c : words[i])
        v[i] |= 1 << (c - 'a');
    }
    for (int i = 0; i < size; i++)
      for (int j = i + 1; j < size; j++)
        if ((v[i] & v[j]) == 0)
          ret = max(ret, (int)words[i].length() * (int)words[j].length());
    return ret;
  }
};
// @lc code=end
