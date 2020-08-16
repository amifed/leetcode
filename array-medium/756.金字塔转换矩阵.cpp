/*
 * @lc app=leetcode.cn id=756 lang=cpp
 *
 * [756] 金字塔转换矩阵
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    map<pair<char, char>, vector<char>> mp;
    bool dfs(string bottom, int idx) {
        if (bottom.length() == 1) {
            return true;
        }
        if (idx == bottom.length() - 1) {
            string sub = bottom.substr(0, bottom.length() - 1);
            return dfs(sub, 0);
        }
        bool ret = false;
        auto p = make_pair(bottom[idx], bottom[idx + 1]);
        for (auto x : mp[p]) {
            string tmp = bottom;
            tmp[idx] = x;
            ret = ret || dfs(tmp, idx + 1);
        }
        return ret;
    }
    bool pyramidTransition(string bottom, vector<string> &allowed) {
        for (auto v : allowed) {
            mp[make_pair(v[0], v[1])].push_back(v[2]);
        }
        return dfs(bottom, 0);
    }
    // TODO 位运算实现状态压缩
};
// @lc code=end
int main(int argc, char const *argv[]) {
    // vector<string> v = {"BCG", "CDE", "GEA", "FFF"};
    // cout << Solution().pyramidTransition("BCD", v);
    cout << (1 << ('G' - 'A'));
    return 0;
}
