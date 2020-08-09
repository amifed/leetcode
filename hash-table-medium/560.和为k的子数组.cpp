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
    int maxNonOverlapping(vector<int> &nums, int target) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, end = -1;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.find(sum - target) != mp.end()) {
                if (mp[sum - target] + 1 > end) {
                    ret++;
                    end = i;
                }
            }
            mp[sum] = i;
        }
        return ret;
    }
};
// @lc code=end
