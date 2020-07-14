/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        int num = 0;
        vector<bool> ret(A.size());
        for (int i = 0; i < A.size(); i++) {
            num = (num << 1) + A[i];
            ret[i] = num % 5 == 0;
            num %= 10;
        }
        return ret;
    }
};
// @lc code=end
