/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 *
 * [1306] 跳跃游戏 III
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (arr[x] == 0) {
                return true;
            }
            if (-1 < x - arr[x] && !visited[x - arr[x]]) {
                q.push(x - arr[x]);
                visited[x - arr[x]] = true;
            }
            if (x + arr[x] < n && !visited[x + arr[x]]) {
                q.push(x + arr[x]);
                visited[x + arr[x]] = true;
            }
        }
        return false;
    }
};
// @lc code=end
