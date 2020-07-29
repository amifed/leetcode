/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */
#include <bits/stdc++.h>
#include <bitset>
using namespace std;
// @lc code=start
class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = 0; i <= N; i++) {
            bitset<20> bit(i);
            string tmp = bit.to_string();
            tmp.erase(0, tmp.find_first_of('1'));
            if (S.find(tmp) == S.npos) return false;
        }
        return true;
    }
};
// @lc code=end
