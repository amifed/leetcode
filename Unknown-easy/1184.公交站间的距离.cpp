/*
 * @lc app=leetcode.cn id=1184 lang=cpp
 *
 * [1184] 公交站间的距离
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  int distanceBetweenBusStops(vector<int> &distance, int start,
                              int destination) {
    int size = distance.size(), clockwise = 0, anticlockwise = 0;
    for (int i = start; i != destination; i = (i + 1) % size)
      clockwise += distance[i];
    for (int i = destination; i != start; i = (i + 1) % size)
      anticlockwise += distance[i];
    return min(clockwise, anticlockwise);
  }
};
// @lc code=end
