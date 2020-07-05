/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // sort
    // int leastInterval(vector<char> &tasks, int n) {
    //     vector<int> map(26, 0);
    //     for (auto &task : tasks)
    //         map[task - 'A']++;
    //     sort(map.begin(), map.end());
    //     int time = 0;
    //     while (map.back() > 0) {
    //         int i = 0;
    //         while (i <= n && map.back() > 0) {
    //             if (i < 26 && map[25 - i] > 0)
    //                 map[25 - i]--;
    //             time++, i++;
    //         }
    //         sort(map.begin(), map.end());
    //     }
    //     return time;
    // }
    // priority_queue
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> map(26, 0);
        for (auto task : tasks)
            map[task - 'A']++;
        priority_queue<int, vector<int>, less<int>> pq;
        for (auto i : map) {
            if (i > 0)
                pq.push(i);
        }
        int time = 0;
        while (!pq.empty()) {
            int cnt = 0;
            vector<int> v;
            while (cnt <= n) {
                if (!pq.empty()) {
                    if (pq.top() > 1)
                        v.push_back(pq.top() - 1);
                    pq.pop();
                }
                time++;
                if (pq.empty() && v.size() == 0)
                    break;
                cnt++;
            }
            for (auto &i : v)
                pq.push(i);
        }
        return time;
    }
};
// @lc code=end
int main() {
    vector<char> v;
    int len, n;
    char data;
    cin >> len;
    for (int i = 0; i < len; i++) {
        cin >> data;
        v.push_back(data);
    }
    cin >> n;
    int result = Solution().leastInterval(v, n);
    cout << result << endl;
    return 0;
}