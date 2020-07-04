/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  bool is_prime(int num) {
    int i;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (i = 5; i * i <= num; i += 6) {
      if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
  }
  int countPrimes(int n) {
    int ret = 0;
    for (int i = 2; i < n; i++) {
      if (is_prime(i)) ret++;
    }
    return ret;
  }
};
// @lc code=end
