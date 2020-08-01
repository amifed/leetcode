/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        int rangeLeft = 0, rangeRight = INT_MAX;
        int n = nums.size();
        vector<int> ptr(n, 0);
        auto cmp = [&](const int &a, const int &b) {
            return nums[a][ptr[a]] > nums[b][ptr[b]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minVal = 0, maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            pq.emplace(i);
            maxVal = max(maxVal, nums[i][0]);
        }
        while (true) {
            int p = pq.top();
            pq.pop();
            minVal = nums[p][ptr[p]];
            if (maxVal - minVal < rangeRight - rangeLeft) {
                rangeLeft = minVal, rangeRight = maxVal;
            }
            if (ptr[p] == nums[p].size() - 1) {
                break;
            }
            ++ptr[p];
            maxVal = max(maxVal, nums[p][ptr[p]]);
            pq.emplace(p);
        }
        return {rangeLeft, rangeRight};
    }
};
// @lc code=end
