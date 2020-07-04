/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int cost = 0, ret = 0;
    int left = 0, right = 0;
    while (right < s.length()) {
      cost += abs(s[right] - t[right]);
      if (cost > maxCost) {
        while (cost > maxCost && left <= right) {
          cost -= abs(s[left] - t[left]);
          left++;
        }
      }
      ret = max(ret, right - left + 1);
      right++;
    }
    return ret;
  }
};
// @lc code=end
// "abcd"\n"cdef"\n3
// "abcd"\n"acde"\n0
// "krrgw"\n"zjxss"\n19
int main() {
  Solution().equalSubstring("krrgw", "zjxss", 19);
  return 0;
}