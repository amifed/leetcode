/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> ret;

public:
    void backtracking(vector<int> &candidates, vector<int> &track, int start, int sum, int target) {
        if (sum > target)
            return;
        if (sum == target) {
            ret.push_back(track);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            track.push_back(candidates[i]);
            backtracking(candidates, track, i, sum + candidates[i], target);
            track.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> track;
        backtracking(candidates, track, 0, 0, target);
        return ret;
    }
};
// @lc code=end
