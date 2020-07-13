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
    // dp from start
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        vector<int> dp(intervals.size());
        dp[0] = 1;
        for (int i = 1; i < intervals.size(); i++) {
            int maxx = 0;
            for (int j = i - 1; j > -1; j--) {
                if (intervals[i][0] >= intervals[j][1])
                    maxx = max(maxx, dp[j]);
            }
            dp[i] = maxx + 1;
        }
        return intervals.size() - dp.back();
    }
    // dp form end
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        int n = intervals.size();
        if (n == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        vector<int> dp(n);
        int ret = 0;
        dp[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            int maxx = 0;
            for (int j = i - 1; j > -1; j--) {
                if (intervals[i][0] >= intervals[j][1]) {
                    maxx = max(maxx, dp[j]);
                    break;
                }
            }
            dp[i] = max(maxx + 1, dp[i - 1]);
            ret = max(ret, dp[i]);
        }
        return n - ret;
    }
    // greedy from end
    // int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    //     sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
    //         return a[1] < b[1];
    //     });
    //     int end = INT_MIN, ret = 0;
    //     for (auto inter : intervals) {
    //         if (inter[0] >= end) {
    //             ret++;
    //             end = inter[1];
    //         }
    //     }
    //     return intervals.size() - ret;
    // }
};
// @lc code=end
