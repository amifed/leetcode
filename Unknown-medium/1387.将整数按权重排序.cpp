/*
 * @lc app=leetcode.cn id=1387 lang=cpp
 *
 * [1387] 将整数按权重排序
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
  unordered_map<int, int> f;

public:
  int getWeight(int x) {
    int ret = 0;
    while (x != 1) {
      if ((x & 1) == 1)
        x = 3 * x + 1;
      else
        x /= 2;
      ret++;
    }
    return ret;
  }
  int getF(int x) {
    if (f.find(x) != f.end())
      return f[x];
    if (x == 1)
      return 0;
    if (x & 1)
      return f[x] = getF(3 * x + 1) + 1;
    else
      return f[x] = getF(x / 2) + 1;
  }
  int getKth(int lo, int hi, int k) {
    vector<int> v;
    for (int i = lo; i <= hi; i++)
      v.push_back(i);
    sort(v.begin(), v.end(), [&](int u, int v) {
      int wu = getF(u), wv = getF(v);
      if (wu != wv)
        return wu < wv;
      else
        return u < v;
    });
    return v[k - 1];
  }
};
// @lc code=end
