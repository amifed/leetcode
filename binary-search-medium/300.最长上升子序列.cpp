/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> d = {nums[0]};
        for (int i = 1; i < n; i++) {
            if (nums[i] > d.back())
                d.push_back(nums[i]);
            else {
                int l = 0, r = d.size();
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[l] = nums[i];
            }
        }
        return d.size();
    }
};
// @lc code=end
