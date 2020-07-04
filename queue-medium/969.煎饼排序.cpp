/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> pancakeSort(vector<int> &A) {
    int n = A.size();
    vector<int> ret;
    for (int i = n; i > 1; i--) {
      auto it = max_element(A.begin(), A.begin() + i) + 1;
      ret.push_back(it - A.begin());
      reverse(A.begin(), it);
      ret.push_back(i);
      reverse(A.begin(), A.begin() + i);
    }
    return ret;
  }
};
// @lc code=end