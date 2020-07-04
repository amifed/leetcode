/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int findComplement(int num) {
    if (num == 0)
      return 1;
    int x = 1, n = num;
    while (n > 0) {
      num ^= x, x <<= 1, n >>= 1;
    }
    return num;
  }
};
// @lc code=end
