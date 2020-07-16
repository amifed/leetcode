/*
 * @lc app=leetcode.cn id=757 lang=cpp
 *
 * [757]  设置交集大小至少为2
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals) {
        // 后开始 先结束
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
        });
        int l = INT_MAX, r = INT_MAX;
        int ret = 0;
        for (auto interval : intervals) {
            if (interval[0] <= l && l <= interval[1] && interval[0] <= r && r <= interval[1])
                continue;
            else if (interval[0] <= l && l <= interval[1]) {
                if (l == interval[0])
                    r = l + 1;
                else
                    r = l, l = interval[0];
                ret++;
            } else if (interval[0] <= r && r <= interval[1]) {
                if (r == interval[0])
                    l = interval[0], r = interval[0] + 1;
                else
                    l = interval[0];
                ret++;
            } else {
                l = interval[0], r = interval[0] + 1;
                ret += 2;
            }
        }
        return ret;
    }
};
// @lc code=end