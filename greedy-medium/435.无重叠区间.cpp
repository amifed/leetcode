/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int end = INT_MIN, ret = 0;
        for (auto inter : intervals) {
            if (inter[0] >= end) {
                ret++;
                end = inter[1];
            }
        }
        return intervals.size() - ret;
    }
};
// @lc code=end
