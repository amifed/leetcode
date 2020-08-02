/*
 * @lc app=leetcode.cn id=1452 lang=cpp
 *
 * [1452] 收藏清单
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>> &f) {
        for_each(f.begin(), f.end(), [&](vector<string> &v) { sort(v.begin(), v.end()); });

        int maxSize = 0;
        map<int, vector<int>> msi;
        for (int i = 0; i < f.size(); i++) {
            msi[f[i].size()].push_back(i);
            maxSize = max(maxSize, (int)f[i].size());
        }

        vector<int> ret;
        for (int i = 0; i < f.size(); i++) {
            bool subset = false;
            for (int n = f[i].size() + 1; n <= maxSize && !subset; n++) {
                for (auto index : msi[n]) {
                    if (includes(f[index].begin(), f[index].end(), f[i].begin(), f[i].end())) {
                        subset = true;
                        break;
                    }
                }
            }
            if (!subset) ret.push_back(i);
        }
        return ret;
    }
};
// @lc code=end
