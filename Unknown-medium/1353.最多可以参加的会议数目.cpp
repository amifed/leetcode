/*
 * @lc app=leetcode.cn id=1353 lang=cpp
 *
 * [1353] 最多可以参加的会议数目
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    vector<vector<int>> start(1e5 + 1);
    for (int i = 0; i < events.size(); i++)
      start[events[i][0]].push_back(i);
    priority_queue<int, vector<int>, greater<int>> pq;
    int ret = 0;
    for (int i = 1; i <= 1e5; i++) {
      for (auto &&v : start[i])
        pq.push(events[v][1]);
      while (!pq.empty() && pq.top() < i)
        pq.pop();
      if (!pq.empty()) {
        pq.pop();
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end
