/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
using namespace std;
// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int max = 0, start = 0;
    map<char, int> map;
    for (int i = 0; i < s.length(); i++) {
      if (map.find(s[i]) != map.end()) start = std::max(start, map[s[i]]);
      max = std::max(max, i - start + 1);
      map[s[i]] = i + 1;
    }
    return max;
  }
};
// @lc code=end
