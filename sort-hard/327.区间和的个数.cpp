/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        multiset<long long> ms;
        long long prefixSum = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ms.insert(prefixSum);
            prefixSum += nums[i];
            auto low = ms.lower_bound(prefixSum - upper);
            auto up = ms.upper_bound(prefixSum - lower);
            ret += distance(low, up);
        }
        return ret;
    }
};
// @lc code=end