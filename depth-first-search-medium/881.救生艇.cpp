/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        int ret = 0;
        sort(people.begin(), people.end());
        auto i = people.begin(), j = people.end() - 1;
        while (i <= j) {
            ret++;
            if (*i + *j <= limit)
                i++;
            j--;
        }
        return ret;
    }
};
// @lc code=end