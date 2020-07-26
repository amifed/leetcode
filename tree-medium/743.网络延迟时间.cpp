/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define MAX 1000000007
class Solution {
public:
    // vector<vector<pair<int, int>>> graph;
    // vector<int> dist;
    // void dfs(int node, int cost) {
    //     if (cost >= dist[node]) return;
    //     dist[node] = cost;
    //     for (auto p : graph[node]) {
    //         dfs(p.second, p.first + cost);
    //     }
    // }
    // int networkDelayTime(vector<vector<int>> &times, int N, int K) {
    //     graph.resize(N + 1);
    //     dist.resize(N + 1, INT_MAX);
    //     for (auto v : times)
    //         graph[v[0]].push_back(pair<int, int>(v[2], v[1]));
    //     for (auto v : graph)
    //         sort(v.begin(), v.end());
    //     dfs(K, 0);
    //     int maxx = *max_element(dist.begin() + 1, dist.end());
    //     return maxx == INT_MAX ? -1 : maxx;
    // }
    // Dijkstra's
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        vector<vector<pair<int, int>>> graph(N + 1);
        for (auto v : times)
            graph[v[0]].push_back(make_pair(v[1], v[2]));
        vector<int> dist(N + 1, INT_MAX);
        vector<bool> visited(N + 1, false);
        dist[K] = 0;
        while (true) {
            int candNode = -1;
            int candDist = INT_MAX;
            for (int i = 1; i < N + 1; i++) {
                if (!visited[i] && dist[i] < candDist) {
                    candNode = i;
                    candDist = dist[i];
                }
            }
            if (candNode == -1) break;
            visited[candNode] = true;
            for (auto p : graph[candNode])
                dist[p.first] = min(dist[p.first], dist[candNode] + p.second);
        }
        int maxx = *max_element(dist.begin() + 1, dist.end());
        return maxx == INT_MAX ? -1 : maxx;
    }
};
// @lc code=end
