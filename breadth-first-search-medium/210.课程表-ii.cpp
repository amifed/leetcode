/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges(numCourses, vector<int>());  //邻接表
    vector<int> indegree(numCourses);                      //入度
    vector<int> ret;
    for (auto&& i : prerequisites) {
      edges[i[1]].push_back(i[0]);
      ++indegree[i[0]];
    }
    queue<int> Q;
    for (int i = 0; i < numCourses; i++)
      if (indegree[i] == 0) Q.push(i);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      ret.push_back(u);
      for (auto&& v : edges[u]) {
        --indegree[v];
        if (indegree[v] == 0) Q.push(v);
      }
    }
    if (ret.size() != numCourses) return {};
    return ret;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  vector<vector<int>> p = {{1, 0}};
  Solution().findOrder(2, p);
  return 0;
}
