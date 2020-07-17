/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string> &A) {
        int ret = 0;
        for (int i = 0; i < A[0].length(); i++) {
            for (int j = 0; j < A.size() - 1; j++) {
                if (A[j][i] > A[j + 1][i]) {
                    ret++;
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
