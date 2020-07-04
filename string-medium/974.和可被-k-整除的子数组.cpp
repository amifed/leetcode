/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int subarraysDivByK(vector<int> &A, int K) {
    unordered_map<int, int> record = {{0, 1}};
    int sum = 0, ret = 0;
    for (auto &&i : A) {
      sum += i;
      int mod = (sum % K + K) % K;
      if (record.find(mod) != record.end())
        ret += record[mod];
      record[mod]++;
    }
    return ret;
  }
};
// @lc code=end
