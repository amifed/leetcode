/*
 * @lc app=leetcode.cn id=849 lang=cpp
 *
 * [849] 到最近的人的最大距离
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        stack<int> sit;
        for (int i = seats.size() - 1; i > -1; i--)
            if (seats[i] == 1)
                sit.push(i);
        int left = 0, ret = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                left = i;
                sit.pop();
            } else {
                if (i == 0)
                    ret = max(ret, sit.empty() ? int(seats.size()) : sit.top() - i);
                else if (i == seats.size() - 1)
                    ret = max(ret, i - left);
                else
                    ret = max(ret, min(i - left, sit.empty() ? int(seats.size()) : sit.top() - i));
            }
        }
        return ret;
    }
};
// @lc code=end