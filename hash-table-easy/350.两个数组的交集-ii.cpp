/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums1.size(); i++)
            um[nums1[i]]++;
        vector<int> ret;
        for (int i = 0; i < nums2.size(); i++) {
            if (um.find(nums2[i]) != um.end()) {
                ret.push_back(nums2[i]);
                um[nums2[i]]--;
                if (um[nums2[i]] == 0)
                    um.erase(nums2[i]);
            }
        }
        return ret;
    }
};
// @lc code=end
