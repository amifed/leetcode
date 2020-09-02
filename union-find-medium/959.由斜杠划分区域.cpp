/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> graph;
    void dfs(int x, int y) {
        int n = graph.size();
        if (x < 0 || x >= n || y < 0 || y >= n || graph[x][y] == 1) {
            return;
        }
        graph[x][y] = 1;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
    }
    int regionsBySlashes(vector<string> &grid) {
        int n = grid.size();
        graph.resize(n * 3, vector<int>(n * 3, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    graph[i * 3][j * 3 + 2] = 1;
                    graph[i * 3 + 1][j * 3 + 1] = 1;
                    graph[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    graph[i * 3][j * 3] = 1;
                    graph[i * 3 + 1][j * 3 + 1] = 1;
                    graph[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (graph[i][j] == 0) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int cnt;
    vector<int> f, r;
    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            if (r[fx] > r[fy]) swap(fx, fy);
            f[fx] = fy;
            if (r[fx] == r[fy]) r[fy]++;
            cnt--;
        }
    }
    int regionsBySlashes(vector<string> &grid) {
        int n = grid.size();
        cnt = 4 * n * n;
        f.resize(4 * n * n);
        r.resize(4 * n * n);
        for (int i = 0; i < 4 * n * n; i++) {
            f[i] = i;
            r[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int p = 4 * (i * n + j);
                if (grid[i][j] == '/') {
                    merge(p, p + 3);
                    merge(p + 1, p + 2);
                } else if (grid[i][j] == '\\') {
                    merge(p, p + 1);
                    merge(p + 2, p + 3);
                } else {
                    merge(p, p + 1);
                    merge(p + 1, p + 3);
                    merge(p + 2, p + 3);
                }

                if (i > 0) merge(p, p - 4 * n + 2);
                if (j < n - 1) merge(p + 1, p + 7);
                if (i < n - 1) merge(p + 2, p + 4 * n);
                if (j > 0) merge(p + 3, p - 3);
            }
        }
        return cnt;
    }
};
// @lc code=end