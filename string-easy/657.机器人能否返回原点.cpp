/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  bool judgeCircle(string moves) {
    unordered_map<char, int> um;
    for (auto &&i : moves)
      um[i]++;
    return um['U'] == um['D'] && um['L'] == um['R'];
  }
};
// @lc code=end
