/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> track;
    vector<vector<int>> ret;
    void backtracking(vector<int> &nums, int start) {
        if (track.size() > 1) {
            ret.push_back(track);
        }
        unordered_set<int> ust;
        for (int i = start; i < nums.size(); i++) {
            if (track.size() > 0 && track.back() > nums[i] || ust.find(nums[i]) != ust.end()) {
                continue;
            }
            ust.insert(nums[i]);
            track.push_back(nums[i]);
            backtracking(nums, i + 1);
            track.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        backtracking(nums, 0);
        return ret;
    }
};
// @lc code=end
// [1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]