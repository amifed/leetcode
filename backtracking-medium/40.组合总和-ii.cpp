/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> ret;
    void backtracking(vector<int> &candidates, vector<int> &track, int start, int sum, int target) {
        if (sum == target) {
            ret.push_back(track);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (sum + candidates[i] > target)
                break;
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            track.push_back(candidates[i]);
            backtracking(candidates, track, i + 1, sum + candidates[i], target);
            track.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> track;
        backtracking(candidates, track, 0, 0, target);
        return ret;
    }
};
// @lc code=end
