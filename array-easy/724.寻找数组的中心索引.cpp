/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int prefix = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (prefix == sum - prefix - nums[i])
                return i;
            prefix += nums[i];
        }
        return -1;
    }
};
// @lc code=end
