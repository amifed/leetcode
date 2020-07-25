/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    using LL = long long;

public:
    bool check(vector<int> &nums, int x, int m) {
        LL sum = 0;
        int cnt = 1;
        for (auto num : nums) {
            if (sum + num > x) {
                cnt++;
                sum = num;
            } else {
                sum += num;
            }
        }
        return cnt <= m;
    }
    int splitArray(vector<int> &nums, int m) {
        LL left = 0, right = 0;
        for (auto num : nums) {
            if (left < num) left = num;
            right += num;
        }
        while (left < right) {
            LL mid = (left + right) >> 1;
            if (check(nums, mid, m))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end
