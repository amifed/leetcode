/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  void backtracking(vector<vector<int>>& ret, vector<int>& track, int start, int n, int k) {
    if (track.size() == k) {
      ret.push_back(track);
      return;
    }
    for (int i = start; i <= n; i++) {
      track.push_back(i);
      backtracking(ret, track, i + 1, n, k);
      track.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    vector<int> track;
    backtracking(ret, track, 1, n, k);
    return ret;
  }
};
// @lc code=end
