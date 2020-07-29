/*
 * @lc app=leetcode.cn id=1389 lang=cpp
 *
 * [1389] 按既定顺序创建目标数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index) {
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            ret.insert(ret.begin() + index[i], nums[i]);
        }
        return ret;
    }
};
// @lc code=end
