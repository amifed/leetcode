#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<pair<int, int>, int> mp;
    int backtracking(vector<int> &pos, vector<int> &track, int m, int start) {
        auto p = make_pair(m, start);
        if (mp.find(p) != mp.end()) {
            return mp[p];
        }
        if (m == 0) {
            int tmp = INT_MAX;
            for (int i = 0; i < track.size(); i++) {
                for (int j = i + 1; j < track.size(); j++) {
                    tmp = min(tmp, abs(track[i] - track[j]));
                }
            }
            return tmp;
        }
        mp[p] = INT_MIN;
        for (int i = start; i < pos.size(); i++) {
            track.push_back(pos[i]);
            mp[p] = max(mp[p], backtracking(pos, track, m - 1, i + 1));
            track.pop_back();
            mp[p] = max(mp[p], backtracking(pos, track, m, i + 1));
        }
        return mp[p];
    }
    int maxDistance(vector<int> &position, int m) {
        vector<int> track;
        sort(position.begin(), position.end());
        return backtracking(position, track, m, 0);
    }
};
// [79,74,57,22]
// 4
// 5
// [269826447,974181916,225871443,189215924,664652743,592895362,754562271,335067223,996014894,510353008,48640772,228945137]
// 3
// 461712236
// [5999,2816,4264,2051,1731,5565]
// 2
// 4268