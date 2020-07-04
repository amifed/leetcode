/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 *
 * [1323] 6 和 9 组成的最大数字
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int maximum69Number(int num) {
    string s = to_string(num);
    for (auto &&c : s) {
      if (c == '6') {
        c = '9';
        break;
      }
    }
    return stoi(s);
  }
};
// @lc code=end
