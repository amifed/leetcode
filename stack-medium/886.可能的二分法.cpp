/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
  vector<vector<int>> graph;
  vector<int> color;

public:
  bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
    graph.resize(N + 1);
    for (auto &&i : dislikes) {
      graph[i[0]].push_back(i[1]);
      graph[i[1]].push_back(i[0]);
    }
    color.resize(N + 1, -1);
    for (int i = 1; i <= N; i++) {
      if (color[i] == -1 && !dfs(i, 0))
        return false;
    }
    return true;
  }
  bool dfs(int i, int c) {
    if (color[i] != -1)
      return color[i] == c;
    color[i] = c;
    for (auto &&j : graph[i])
      if (!dfs(j, c ^ 1))
        return false;
    return true;
  }
};
// @lc code=end
