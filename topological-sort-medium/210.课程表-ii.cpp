/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<vector<int>> edges;
  vector<int> visited;
  vector<int> ret;
  bool invalid;

 public:
  void dfs(int u) {
    visited[u] = 1;
    for (auto&& v : edges[u]) {
      if (visited[v] == 0) {
        dfs(v);
        if (invalid) return;
      } else if (visited[v] == 1) {
        invalid = true;
        return;
      }
    }
    visited[u] = 2;
    ret.push_back(u);
  }
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    visited.resize(numCourses);
    for (auto&& i : prerequisites) edges[i[1]].push_back(i[0]);
    for (int i = 0; i < numCourses && !invalid; i++)
      if (!visited[i]) dfs(i);
    if (invalid) return {};
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
// @lc code=end
