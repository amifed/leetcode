/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int numRabbits(vector<int> &answers) {
        int count[1000] = {0};
        for (auto x : answers) {
            count[x]++;
        }
        int ret = 0;
        for (int i = 0; i < 1000; i++) {
            ret += (count[i] / (i + 1) + (count[i] % (i + 1) != 0)) * (i + 1);
        }
        return ret;
    }
};
// @lc code=end
