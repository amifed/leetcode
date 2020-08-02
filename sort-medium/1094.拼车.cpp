/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        int caps[1001] = {0};
        for (auto v : trips) {
            caps[v[2]] -= v[0];
            caps[v[1]] += v[0];
        }
        int cap = 0;
        for (auto i : caps) {
            cap += i;
            if (cap > capacity) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end