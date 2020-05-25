/*
 * @lc app=leetcode.cn id=1297 lang=cpp
 *
 * [1297] 子串的最大出现次数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  // int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
  //   int n = s.size();
  //   unordered_map<string, int> um;
  //   int ret = 0;
  //   for (int i = 0; i < n; i++) {
  //     unordered_set<char> exist;
  //     string sub;
  //     for (int j = i; j < min(n, i + maxSize); j++) {
  //       exist.insert(s[j]);
  //       if (exist.size() > maxLetters)
  //         break;
  //       sub.push_back(s[j]);
  //       if (j - i + 1 >= minSize) {
  //         um[sub]++;
  //         ret = max(ret, um[sub]);
  //       }
  //     }
  //   }
  //   return ret;
  // }
  // 本题 maxSize 无用，因为
  // 长的字符串重复出现，其子串（短的字符串）也重复出现。
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int n = s.size();
    unordered_map<string, int> um;
    int ret = 0;
    for (int i = 0; i < n - minSize + 1; i++) {
      string sub = s.substr(i, minSize);
      unordered_set<char> exist(sub.begin(), sub.end());
      if (exist.size() <= maxLetters) {
        um[sub]++;
        ret = max(ret, um[sub]);
      }
    }
    return ret;
  }
};
// @lc code=end
// "aababcaab"\n2\n3\n4
// "aaaa"\n1\n3\n3
// "aabcabcab"\n2\n2\n3