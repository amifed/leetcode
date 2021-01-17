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
const double EPS = 1e-6;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 4e4 + 7;

int p[N], sz[N];
int n, m;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int get(int x, int y) { return x * m + y; }
int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}
void unionn(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) sz[ry] += sz[rx], p[rx] = ry;
}

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>> &g, vector<vector<int>> &hs) {
        n = g.size(), m = g[0].size();
        for (int i = 0; i <= n * m; ++i)
            p[i] = i, sz[i] = 1;
        vector<vector<int>> t = g;
        for (auto &v : hs)
            t[v[0]][v[1]] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (t[i][j]) {
                    if (i == 0) unionn(n * m, get(i, j));
                    if (i > 0 && t[i - 1][j]) unionn(get(i, j), get(i - 1, j));
                    if (j > 0 && t[i][j - 1]) unionn(get(i, j), get(i, j - 1));
                }
            }
        }

        vector<int> ans(hs.size(), 0);
        for (int i = hs.size() - 1; i >= 0; --i) {
            int x = hs[i][0], y = hs[i][1];
            if (!g[x][y]) continue;

            int p = sz[find(n * m)];

            if (x == 0) unionn(n * m, get(x, y));
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if (t[nx][ny] == 1) unionn(get(x, y), get(nx, ny));
                }
            }

            int q = sz[find(n * m)];
            ans[i] = max(0, q - p - 1);
            t[x][y] = 1;
        }
        return ans;
    }
};