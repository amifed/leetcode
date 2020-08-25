/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/* class Solution {
public:
    int n;
    vector<int> tmp;
    vector<vector<int>> ans;
    unordered_set<int> st;
    void findSubsequences(int mask, vector<int> &nums) {
        tmp.clear();
        for (int i = 0; i < n; i++) {
            if (mask & 1) {
                tmp.push_back(nums[i]);
            }
            mask >>= 1;
        }
    }
    bool check() {
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i] < tmp[i - 1]) {
                return false;
            }
        }
        return tmp.size() > 1;
    }
    int getHash(int base, int mod) {
        int hash = 0;
        for (auto &x : tmp) {
            hash = 1LL * hash * base % mod + (x + 101);
            hash %= mod;
        }
        return hash;
    }
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            findSubsequences(i, nums);
            int hash = getHash(263, 1e9 + 7);
            if (check() && st.find(hash) == st.end()) {
                st.insert(hash);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
}; */
// @lc code=end
// [1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]