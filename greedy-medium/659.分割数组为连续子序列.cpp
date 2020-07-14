/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> count, need;
        for (int num : nums)
            count[num]++;
        for (int num : nums) {
            if (count[num] == 0) //用完
                continue;
            else if (need[num] > 0) { //连接形成最长序列
                need[num]--;
                need[num + 1]++;
            } else if (count[num + 1] > 0 && count[num + 2] > 0) { //形成新的三元组
                count[num + 1]--;
                count[num + 2]--;
                need[num + 3]++;
            } else
                return false;
            count[num]--;
        }
        return true;
    }
};
// @lc code=end