/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    int target;

public:
    bool dfs(vector<int> &nums, vector<int> &groups, int index) {
        if (index < 0) return true;
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] + nums[index] <= target) {
                groups[i] += nums[index];
                if (dfs(nums, groups, index - 1)) return true;
                groups[i] -= nums[index];
            }
            if (groups[i] == 0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k > 0) return false;

        target = sum / k;

        sort(nums.begin(), nums.end());
        int index = nums.size() - 1;
        if (nums[index] > target) return false;

        while (index > -1 && nums[index] == target)
            index--, k--;

        vector<int> groups(k, 0);
        return dfs(nums, groups, index);
    }
};
// @lc code=end
