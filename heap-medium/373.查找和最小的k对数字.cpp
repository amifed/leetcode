/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
typedef pair<int, vector<int>> P;
class Solution {
public:
    // vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    //     vector<vector<int>> ret;
    //     int n1 = nums1.size(), n2 = nums2.size();
    //     if (n1 == 0 || n2 == 0 || k == 0)
    //         return ret;
    //     priority_queue<P, vector<P>, greater<P>> pq;
    //     for (int i = 0; i < n1; i++)
    //         for (int j = 0; j < n2; j++)
    //             pq.push(P(nums1[i] + nums2[j], {nums1[i], nums2[j]}));
    //     while (k-- && !pq.empty()) {
    //         ret.push_back(pq.top().second);
    //         pq.pop();
    //     }
    //     return ret;
    // }
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<vector<int>> ret;
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0 || n2 == 0 || k == 0)
            return ret;
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int i = 0; i < n1; i++)
            pq.push(P(nums1[i] + nums2[0], {i, 0}));
        while (k-- && !pq.empty()) {
            auto pos = pq.top().second;
            pq.pop();
            ret.push_back({nums1[pos[0]], nums2[pos[1]]});
            if (pos[1] + 1 < n2)
                pq.push(P(nums1[pos[0]] + nums2[pos[1] + 1], {pos[0], pos[1] + 1}));
        }
        return ret;
    }
};
// @lc code=end
