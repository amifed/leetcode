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
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (auto v : prerequisites) {
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int ret = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            ret++;
            for (auto x : graph[node]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        return ret == numCourses;
    }
};
// @lc code=end
