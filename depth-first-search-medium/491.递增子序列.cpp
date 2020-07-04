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
  void backtracking(vector<int> &nums, vector<vector<int>> &ret,
                    vector<int> &track, int start) {
    if (track.size() > 1)
      ret.push_back(track);
    unordered_set<int> s;
    for (int i = start; i < nums.size(); i++) {
      if (track.size() > 0 && nums[i] < track.back() ||
          s.find(nums[i]) != s.end())
        continue;
      s.insert(nums[i]);
      track.push_back(nums[i]);
      backtracking(nums, ret, track, i + 1);
      track.pop_back();
    }
  }
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<int> track;
    vector<vector<int>> ret;
    backtracking(nums, ret, track, 0);
    return ret;
  }
};
// @lc code=end
// [1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]
