/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    map<int, int> m;
    vector<int> ret(2);
    for (auto &&i : nums)
      m[i]++;
    for (int i = 1; i <= nums.size(); i++) {
      if (m.find(i) != m.end()) {
        if (m[i] == 2)
          ret[0] = i;
      } else
        ret[1] = i;
    }
    return ret;
  }
};
// @lc code=end
