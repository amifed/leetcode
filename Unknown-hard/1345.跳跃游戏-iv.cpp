/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minJumps(vector<int> &arr) {
        int n = arr.size();
        if (n == 1) {
            return 0;
        }
        unordered_map<int, vector<int>> ump;
        for (int i = 0; i < n; i++) {
            ump[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[0] = 0;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (x - 1 > -1 && !visited[x - 1]) {
                dist[x - 1] = dist[x] + 1;
                q.push(x - 1);
                visited[x - 1] = true;
            }
            if (x + 1 < n && !visited[x + 1]) {
                dist[x + 1] = dist[x] + 1;
                q.push(x + 1);
                visited[x + 1] = true;
            }
            if (ump.find(arr[x]) != ump.end()) {
                for (auto i : ump[arr[x]]) {
                    if (!visited[i]) {
                        dist[i] = dist[x] + 1;
                        q.push(i);
                        visited[i] = true;
                    }
                }
                ump.erase(x);
            }
        }
        return dist[n - 1];
    }
};
// @lc code=end
