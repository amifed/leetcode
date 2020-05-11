/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  // 暴力
  // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  //   int size = gas.size();
  //   for (int i = 0; i < size; i++) {
  //     if (gas[i] < cost[i]) continue;
  //     int oil = 0, n = 0;
  //     for (int j = i; n < size; j = (j + 1) % size, n++) {
  //       oil += gas[j];
  //       if (oil < cost[j]) break;
  //       oil -= cost[j];
  //     }
  //     if (n == size) return i;
  //   }
  //   return -1;
  // }
  // 优化
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size = gas.size();
    int total = 0, curr = 0, start = 0;
    for (int i = 0; i < size; i++) {
      total += gas[i] - cost[i];
      curr += gas[i] - cost[i];
      if (curr < 0) {
        start = i + 1;
        curr = 0;
      }
    }
    return total >= 0 ? start : -1;
  }
};
// @lc code=end
// [2,3,4]\n[3,4,3]