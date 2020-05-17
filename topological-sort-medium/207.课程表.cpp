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
  void dfs(int u, bool& invalid, vector<int>& visited,
           vector<vector<int>> edges) {
    visited[u] = 1;
    for (auto&& v : edges[u]) {
      if (visited[v] == 0) {
        dfs(v, invalid, visited, edges);
        if (invalid) return;
      } else if (visited[v] == 1) {
        invalid = true;
        return;
      }
    }
    visited[u] = 2;
  }
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if(prerequisites.size() == 0) return true;
    bool invalid = false;
    vector<int> visited(numCourses, 0);
    vector<vector<int>> edges(numCourses, vector<int>());
    for (auto&& i : prerequisites) edges[i[1]].push_back(i[0]);
    for (int i = 0; i < numCourses; i++)
      if (!visited[i]) dfs(i, invalid, visited, edges);
    return !invalid;
  }
};
// @lc code=end
