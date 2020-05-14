/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int bitwiseComplement(int N) {
    if (N == 0)
      return 1;
    int x = 1, n = N;
    while (n > 0) {
      N ^= x;
      x <<= 1;
      n >>= 1;
    }
    return N;
  }
};
// @lc code=end
