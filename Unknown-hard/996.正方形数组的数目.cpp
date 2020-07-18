/*
 * @lc app=leetcode.cn id=996 lang=cpp
 *
 * [996] 正方形数组的数目
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> track;
    vector<bool> visited;
    set<vector<int>> sett;
    unordered_map<int, int> counter;
    unordered_map<int, vector<int>> graph;
    void backtracking(vector<int> &A) {
        if (track.size() == A.size()) {
            sett.insert(track);
            return;
        }
        for (auto num : graph[track.back()]) {
            if (counter[num] == 0) continue;
            counter[num]--;
            track.push_back(num);
            backtracking(A);
            track.pop_back();
            counter[num]++;
        }
    }
    int numSquarefulPerms(vector<int> &A) {
        visited.resize(A.size(), false);
        for (auto i : A)
            counter[i]++;
        for (auto p : counter) {
            for (auto q : counter)
                if (int(pow(int(sqrt(p.first + q.first)), 2)) == p.first + q.first)
                    graph[p.first].push_back(q.first);
        }
        for (auto a : A) {
            counter[a]--;
            track.push_back(a);
            backtracking(A);
            track.pop_back();
            counter[a]++;
        }
        return sett.size();
    }
};
// @lc code=end