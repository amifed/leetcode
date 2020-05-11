/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 *
 * [1054] 距离相等的条形码
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    vector<int> ret;
    map<int, int> nums_map;
    int size = barcodes.size();
    for (auto&& i : barcodes) nums_map[i]++;
    priority_queue<pair<int, int>> pq;
    for (auto&& i : nums_map) pq.push({i.second, i.first});
    while (pq.size() > 1) {
      auto t1 = pq.top();
      pq.pop();
      auto t2 = pq.top();
      pq.pop();
      ret.push_back(t1.second), ret.push_back(t2.second);
      if (--t1.first > 0) pq.push(t1);
      if (--t2.first > 0) pq.push(t2);
    }
    if (pq.size() > 0) ret.push_back(pq.top().second);
    return ret;
  }
};
// @lc code=end
// [1,1,2]
// [1,2,1,1,2,1,2]
// [1,2,2,3]
// [2,2,2,1,5]
// [1,1,1,1,2,2,3,3]
// [7,7,7,8,5,7,5,5,5,8]
int main() {
  vector<int> barcodes = {2, 2, 2, 1, 5};
  Solution().rearrangeBarcodes(barcodes);
  return 0;
}