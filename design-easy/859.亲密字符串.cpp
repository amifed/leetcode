/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  bool buddyStrings(string A, string B) {
    if (A.length() != B.length())
      return false;
    int first = -1, second = -1, third = -1;
    if (A == B) {
      int hash[26] = {0};
      for (auto &&c : A)
        hash[c - 'a']++;
      for (auto &&i : hash)
        if (i > 1)
          return true;
      return false;
    } else {
      for (int i = 0; i < A.length(); i++) {
        if (A[i] == B[i])
          continue;
        if (first == -1)
          first = i;
        else if (second == -1)
          second = i;
        else {
          third = i;
        }
      }
      return first != -1 && second != -1 && A[first] == B[second] &&
             A[second] == B[first] && third == -1;
    }
  }
};
// @lc code=end
