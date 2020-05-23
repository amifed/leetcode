/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> um;
    for (auto &&s : words)
      um[s]++;
    vector<pair<string, int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), [&](pair<string, int> a, pair<string, int> b) {
      return a.second != b.second ? a.second > b.second : a.first < b.first;
    });
    vector<string> ret;
    for (int i = 0; i < k; i++)
      ret.push_back(v[i].first);
    return ret;
  }
};
// @lc code=end
