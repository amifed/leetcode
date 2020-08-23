/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define it insert
#define pob pop_back
#define pub push_back
#define emb emplace_back
#define all(v) (v).begin(), (v).end()
using LL = long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
class Solution {
public:
    const int TARGET = 24;
    const double EPSILON = 1e-6;
    bool judgePoint24(vector<int> &nums) {
        vector<double> l;
        for (auto &num : nums) {
            l.emb(num);
        }
        return solve(l);
    }
    bool solve(vector<double> &l) {
        if (l.size() == 0) {
            return false;
        }
        if (l.size() == 1) {
            return fabs(l[0] - TARGET) < EPSILON;
        }
        int size = l.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    continue;
                }
                vector<double> l2;
                for (int k = 0; k < size; k++) {
                    if (k != i && k != j) {
                        l2.emb(l[k]);
                    }
                }
                for (int k = 0; k < 4; k++) {
                    if (k < 2 && i > j) {
                        continue;
                    }
                    if (k == 0) {
                        l2.emb(l[i] + l[j]);
                    } else if (k == 1) {
                        l2.emb(l[i] * l[j]);
                    } else if (k == 2) {
                        l2.emb(l[i] - l[j]);
                    } else {
                        if (fabs(l[j]) < EPSILON) continue;
                        l2.emb(l[i] / l[j]);
                    }
                    if (solve(l2)) return true;
                    l2.pob();
                }
            }
        }
        return false;
    }
};
// @lc code=end
