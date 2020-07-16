/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */
#include <stdio.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        int ret = 0, i = 0, m = nums.size();
        long long miss = 1;
        while (miss <= n) {
            if (i < m && nums[i] <= miss)
                miss += nums[i++];
            else {
                miss <<= 1;
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end