/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool divisorGame(int N) {
        // vector<bool> f(N + 1, false);
        // f[1] = false;
        // f[2] = true;
        // for (int i = 3; i <= N; i++) {
        //     for (int j = 1; j < i; j++) {
        //         if (i % j == 0 && !f[i - j]) {
        //             f[i] = true;
        //             break;
        //         }
        //     }
        // }
        // return f[N];
        return !(N & 1);
    }
};
// @lc code=end
