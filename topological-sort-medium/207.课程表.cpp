/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    int ret = 0;
    for (auto&& i : prerequisites) {
      edges[i[0]].push_back(i[1]);
      ++indegree[i[1]];
    }
    queue<int> Q;
    for (int i = 0; i < numCourses; i++)
      if (indegree[i] == 0) Q.push(i);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop(), ret++;
      for (auto&& v : edges[u]) {
        --indegree[v];
        if (indegree[v] == 0) Q.push(v);
      }
    }
    return ret == numCourses;
  }
};
// @lc code=end
