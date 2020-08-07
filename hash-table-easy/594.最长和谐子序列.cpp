/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> counter;
        int ret = 0;
        for (auto num: nums){
            counter[num]++;
            if (counter.find(num - 1) != counter.end()){
                ret = max(ret, counter[num] + counter[num - 1]);
            }
            if (counter.find(num + 1) != counter.end()){
                ret = max(ret, counter[num] + counter[num + 1]);
            }
        }
        return ret;
    }
};
// @lc code=end

