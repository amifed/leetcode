/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<string,
                  priority_queue<string, vector<string>, greater<string>>>
        gh;
    vector<string> stk;
    vector<string> findItinerary(vector<vector<string>> &ts) {
        for (auto &t : ts) {
            gh[t[0]].emplace(t[1]);
        }
        dfs("JFK");
        reverse(stk.begin(), stk.end());
        return stk;
    }
    void dfs(const string &f) {
        while (gh.find(f) != gh.end() && !gh[f].empty()) {
            auto t = gh[f].top();
            gh[f].pop();
            dfs(t);
        }
        stk.push_back(f);
    }
};
// @lc code=end
