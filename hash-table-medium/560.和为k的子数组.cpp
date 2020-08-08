/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ret = 0, prefixSum = 0;
        for (auto &x : nums) {
            prefixSum += x;
            if (mp.find(prefixSum - k) != mp.end()) {
                ret += mp[prefixSum - k];
            }
            mp[prefixSum]++;
        }
        return ret;
    }
};
// @lc code=end
