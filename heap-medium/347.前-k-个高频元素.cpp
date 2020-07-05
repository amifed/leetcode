/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // vector<int> topKFrequent(vector<int> &nums, int k) {
    //     unordered_map<int, int> um;
    //     for (auto num : nums)
    //         um[num]++;
    //     priority_queue<pair<int, int>> pq;
    //     for (auto m : um)
    //         pq.push(pair<int, int>(m.second, m.first));
    //     vector<int> ret;
    //     for (int i = 0; i < k; i++) {
    //         ret.push_back(pq.top().second);
    //         pq.pop();
    //     }
    //     return ret;
    // };
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> um;
        for (auto num : nums)
            um[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto m : um)
            if (k-- > 0)
                pq.push(pair<int, int>(m.second, m.first));
            else if (pq.top().first < m.second) {
                pq.pop();
                pq.push(pair<int, int>(m.second, m.first));
            }
        vector<int> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end
int main() {
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> k;
    vector<int> ret = Solution().topKFrequent(v, k);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
        if (i < ret.size() - 1)
            cout << ' ';
    }
    return 0;
}