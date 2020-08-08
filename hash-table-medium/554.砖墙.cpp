/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * {554] 砖墙
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> mp;
        for (auto v : wall) {
            int sum = 0;
            for (int i = 0; i < v.size() - 1; i++) {
                sum += v[i];
                mp[sum]++;
            }
        }
        int ret = 0;
        for_each(mp.begin(), mp.end(), [&ret](map<int, int>::value_type &p) {
            ret = max(ret, p.second);
        });
        return wall.size() - ret;
    }
};
// @lc code=end
