/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
  int oper(int n) {
    return (1 + n) * n / 2;
  }
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int ret = 0;
    unordered_map<int, int> um;
    for (auto&& i : dominoes) {
      int n = i[0] * 10 + i[1], rn = i[1] * 10 + i[0];
      if (um.find(rn) != um.end())
        um[rn]++;
      else
        um[n]++;
    }
    for (auto&& i : um) {
      if (i.second > 1) ret += oper(i.second - 1);
    }
    return ret;
  }
};
// @lc code=end
// [[1,2],[1,2],[1,2],[2,1],[2,1],[5,6]]
int main() {
  vector<vector<int>> doms = {{1, 2}, {1, 2}, {1, 2}, {2, 1}, {2, 1}, {5, 6}};
  Solution().numEquivDominoPairs(doms);
  return 0;
}
