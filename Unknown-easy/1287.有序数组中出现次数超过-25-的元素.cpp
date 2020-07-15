/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // count
    // int findSpecialInteger(vector<int> &arr) {
    //     int i = 0, j = 0;
    //     while (i < arr.size() && j < arr.size()) {
    //         while (j < arr.size() && arr[i] == arr[j])
    //             j++;
    //         if (j - i > arr.size() / 4)
    //             return arr[i];
    //         i = j;
    //     }
    //     return -1;
    // }
    // binary search
    int findSpecialInteger(vector<int> &arr) {
        int span = arr.size() / 4 + 1;
        for (int i = 0; i < arr.size(); i += span) {
            auto iter_l = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto iter_r = upper_bound(arr.begin(), arr.end(), arr[i]);
            if (iter_r - iter_l >= span)
                return arr[i];
        }
        return -1;
    }
};
// @lc code=end
