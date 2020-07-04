/*
 * @lc app=leetcode.cn id=1318 lang=cpp
 *
 * [1318] 或运算的最小翻转次数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int minFlips(int a, int b, int c) {
    int ret = 0;
    for (int i = 0; i < 31; i++) {
      int bit_a = (a >> i) & 1;
      int bit_b = (b >> i) & 1;
      int bit_c = (c >> i) & 1;
      if (bit_c == 0)
        ret += bit_a + bit_b;
      else
        ret += (bit_a + bit_b == 0);
    }
    return ret;
  }
};
// @lc code=end
