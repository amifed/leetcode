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
    vector<string> ret;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> ump;
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto v : tickets) {
            ump[v[0]].push(v[1]);
        }
        dfs("JFK");
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void dfs(string start) {
        while (ump.find(start) != ump.end() && !ump[start].empty()) {
            auto end = ump[start].top();
            ump[start].pop();
            dfs(end);
        }
        ret.push_back(start);
    }
};
// @lc code=end
