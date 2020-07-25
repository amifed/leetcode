/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findJudge(int N, vector<vector<int>> &trust) {
        vector<int> in(N + 1, 0), out(N + 1, 0);
        for (auto v : trust) {
            out[v[0]]++, in[v[1]]++;
        }
        for (int i = 1; i < N + 1; i++) {
            if (in[i] == N - 1 && out[i] == 0) return i;
        }
        return -1;
    }
};
// @lc code=end
