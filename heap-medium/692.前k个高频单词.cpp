/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
  struct cmp {
    bool operator()(pair<string, int> &a, pair<string, int> &b) {
      return a.second != b.second ? a.second < b.second : a.first > b.first;
    }
  };

public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> um;
    for (auto &&s : words)
      um[s]++;
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq(
        um.begin(), um.end());
    vector<string> ret;
    while (k) {
      ret.push_back(pq.top().first);
      pq.pop();
      k--;
    }
    return ret;
  }
};
// @lc code=end
