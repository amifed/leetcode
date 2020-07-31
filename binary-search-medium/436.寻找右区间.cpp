/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// sort
// struct pair_hash {
//     template <typename T, typename U>
//     size_t operator()(const pair<T, U> &x) const {
//         return hash<T>()(x.first) ^ hash<U>()(x.second);
//     }
// };
// class Solution {
// public:
//     vector<int> findRightInterval(vector<vector<int>> &intervals) {
//         using PII = pair<int, int>;
//         unordered_map<PII, int, pair_hash> mp;
//         for (int i = 0; i < intervals.size(); i++) {
//             mp[make_pair(intervals[i][0], intervals[i][1])] = i;
//         }
//         sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b) {
//             return a[0] < b[0];
//         });
//         vector<int> ret(intervals.size());
//         for (int i = 0; i < intervals.size(); i++) {
//             int minn = INT_MAX, minnIndex = -1;
//             for (int j = i + 1; j < intervals.size(); j++) {
//                 if (intervals[j][0] >= intervals[i][1] && intervals[j][0] < minn) {
//                     minn = intervals[j][0];
//                     minnIndex = mp[make_pair(intervals[j][0], intervals[j][1])];
//                 }
//             }
//             ret[mp[make_pair(intervals[i][0], intervals[i][1])]] = minnIndex;
//         }
//         return ret;
//     }
// };
// binary-search
class Solution {
public:
    int binary_search(vector<pair<int, int>> &pairs, int num) {
        int l = 0, r = pairs.size() - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (pairs[m].first < num) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l == pairs.size() ? -1 : pairs[l].second;
    }
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < intervals.size(); i++) {
            pairs.push_back(make_pair(intervals[i][0], i));
        }
        sort(pairs.begin(), pairs.end());
        vector<int> ret;
        for (int i = 0; i < intervals.size(); i++) {
            ret.push_back(binary_search(pairs, intervals[i][1]));
        }
        long a = LLONG_MIN
        return ret;
    }
};
// @lc code=end
