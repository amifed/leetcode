/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int> &height) {
        if (height.empty())
            return 0;
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);

        maxLeft[0] = height[0];
        for (int i = 1; i < height.size(); i++)
            maxLeft[i] = max(maxLeft[i - 1], height[i]);

        maxRight[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            maxRight[i] = max(maxRight[i + 1], height[i]);

        int ret = 0;
        for (int i = 1; i < n - 1; i++)
            ret += (min(maxLeft[i], maxRight[i]) - height[i]);
        return ret;
    }
};
// @lc code=end
