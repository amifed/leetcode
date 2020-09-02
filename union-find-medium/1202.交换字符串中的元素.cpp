/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
const int MAXN = 1e5 + 7;
int f[MAXN], r[MAXN];
class Solution {
public:
    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            if (r[fx] > r[fy]) swap(fx, fy);
            f[fx] = fy;
            if (r[fx] == r[fy]) fy++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>> &ps) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
        for (auto &p : ps) {
            merge(p[0], p[1]);
        }
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>>
            mpq;
        for (int i = 0; i < n; i++) {
            mpq[find(i)].push(s[i]);
        }
        for (int i = 0; i < n; i++) {
            int p = find(i);
            s[i] = mpq[p].top();
            mpq[p].pop();
        }
        return s;
    }
};
// @lc code=end