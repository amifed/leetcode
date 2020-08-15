/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    map<vector<int>, int> memo;
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        return dfs(price, special, needs);
    }
    int dfs(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        if (memo.find(needs) != memo.end()) {
            return memo[needs];
        }
        int ret = 0;
        for (int i = 0; i < needs.size(); i++) {
            ret += price[i] * needs[i];
        }
        for (auto v : special) {
            bool flag = true;
            vector<int> tmp(needs.begin(), needs.end());
            for (int i = 0; i < needs.size(); i++) {
                tmp[i] -= v[i];
                if (v[i] > needs[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ret = min(ret, v.back() + dfs(price, special, tmp));
            }
        }
        return memo[needs] = ret;
    }
};
// @lc code=end