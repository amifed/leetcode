/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // int shortestSubarray(vector<int> &A, int K) {
    //     int ret = INT_MAX;
    //     vector<long> prefix(A.size() + 1, 0);
    //     for (int i = 0; i < A.size(); i++) {
    //         prefix[i + 1] = prefix[i] + A[i];
    //     }
    //     for (int i = 1; i < prefix.size(); i++) {
    //         for (int j = i - 1; j >= 0; j--) {
    //             if (prefix[i] - prefix[j] >= K) {
    //                 ret = min(ret, i - j);
    //                 break;
    //             }
    //         }
    //     }
    //     return ret == INT_MAX ? -1 : ret;
    // }
    int shortestSubarray(vector<int> &A, int K) {
        vector<long> prefix(A.size() + 1, 0);
        for (int i = 0; i < A.size(); i++)
            prefix[i + 1] = prefix[i] + A[i];
        int ret = INT_MAX;
        deque<int> dq;
        for (int i = 0; i < prefix.size(); i++) {
            while (!dq.empty() && prefix[i] <= prefix[dq.front()]) {
                dq.pop_front();
            }
            while (!dq.empty() && prefix[i] - prefix[dq.back()] >= K) {
                ret = min(ret, i - dq.back());
                dq.pop_back();
            }
            dq.push_front(i);
        }
        return ret == INT_MAX ? -1 : ret;
    }
};
// @lc code=end
