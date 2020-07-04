/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  // vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
  //   vector<int> ret;
  //   map<int, int> m;
  //   for (auto &&i : arr1)
  //     m[i]++;
  //   for (int i = 0; i < arr2.size(); i++) {
  //     for (int j = 0; j < m[arr2[i]]; j++) {
  //       ret.push_back(arr2[i]);
  //     }
  //     m.erase(arr2[i]);
  //   }
  //   for (auto &&i : m) {
  //     for (int j = 0; j < i.second; j++) {
  //       ret.push_back(i.first);
  //     }
  //   }
  //   return ret;
  // }
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    int pos = 0;
    for (int i = 0; i < arr2.size(); i++)
      for (int j = 0; j < arr1.size(); j++)
        if (arr2[i] == arr1[j])
          swap(arr1[j], arr1[pos++]);
    sort(arr1.begin() + pos, arr1.end());
    return arr1;
  }
};
// @lc code=end
