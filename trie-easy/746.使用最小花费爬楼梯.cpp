/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int f1 = 0, f2 = 0;
        for (int i = 0; i < cost.size(); i++) {
            int tmp = f2;
            f2 = min(f1, f2) + cost[i];
            f1 = tmp;
        }
        return min(f1, f2);
    }
};
// @lc code=end