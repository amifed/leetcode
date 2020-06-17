/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &A) {
        int ret = 0, maxScore = A[0];
        for (int i = 1; i < A.size(); i++) {
            ret = max(ret, maxScore + A[i] - i);
            maxScore = max(maxScore, A[i] + i);
        }
        return ret;
    }
};
// @lc code=end
