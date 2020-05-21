/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int count(int n, long prefix) {
    long next = prefix + 1;
    int cnt = 0;
    while (prefix <= n) {
      cnt += min(next, (long)n + 1) - prefix;
      prefix *= 10, next *= 10;
    }
    return cnt;
  }
  int findKthNumber(int n, int k) {
    int ret = 1;
    k--;
    while (k > 0) {
      int cnt = count(n, ret);
      if (cnt <= k) {
        ret += 1;
        k -= cnt;
      } else {
        ret *= 10;
        k -= 1;
      }
    }
    return ret;
  }
};
// @lc code=end
int main() {
  cout << Solution().count(103, 1) << endl;
  return 0;
}