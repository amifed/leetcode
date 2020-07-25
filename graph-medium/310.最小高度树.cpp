/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 1 || degree[i] == 0)
                q.push(i);
        while (n != 1 && n != 2) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                for (auto x : graph[node]) {
                    if (degree[x] > 0) degree[x]--;
                    if (degree[x] == 1) q.push(x);
                }
            }
            n -= size;
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
// @lc code=end
