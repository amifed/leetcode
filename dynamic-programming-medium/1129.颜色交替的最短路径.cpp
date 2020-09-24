/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#define it insert
#define pob pop_back
#define pub push_back
#define emb emplace_back
#define all(v) (v).begin(), (v).end()
#define mkp(a, b) make_pair(a, b)
using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 7;

// @lc code=start
const int N = 107, INF = 0x3f3f3f3f;
class Solution {
public:
    int d[N][2], vt[N][2];
    vector<vector<vector<int>>> g;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges,
                                         vector<vector<int>> &blue_edges) {
        g.resize(2, vector<vector<int>>(n));
        for (auto &v : red_edges)
            g[0][v[0]].push_back(v[1]);
        for (auto &v : blue_edges)
            g[1][v[0]].push_back(v[1]);
        memset(d, 0x3f, sizeof d);
        memset(vt, 0, sizeof vt);
        queue<pair<int, int>> q;
        q.push({0, 0}); // red
        q.push({0, 1}); // blue
        vt[0][0] = vt[0][1] = 1;
        d[0][0] = d[0][1] = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto &x : g[!p.second][p.first]) {
                if (!vt[x][!p.second]) {
                    vt[x][!p.second] = 1;
                    d[x][!p.second] = d[p.first][p.second] + 1;
                    q.push({x, !p.second});
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (d[i][0] == INF && d[i][1] == INF)
                ans.push_back(-1);
            else
                ans.push_back(min(d[i][0], d[i][1]));
        }
        return ans;
    }
};
// @lc code=end