/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct Node {
    int cost, k, node;
    Node(int cost, int k, int node) : cost(cost), k(k), node(node) {}
};
struct cmp {
    bool operator()(Node &a, Node &b) {
        return a.cost > b.cost;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto f : flights) {
            graph[f[0]].push_back(make_pair(f[1], f[2]));
        }
        map<pair<int, int>, int> best;
        priority_queue<Node, vector<Node>, cmp> pq;
        pq.push({0, 0, src});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            if (p.k > K + 1 || (best.find({p.k, p.node}) != best.end() && p.cost > best[{p.k, p.node}]))
                continue;

            if (p.node == dst)
                return p.cost;

            for (auto m : graph[p.node]) {
                int newCost = p.cost + m.second;
                if (best.find({p.k + 1, m.first}) == best.end() || newCost < best[{p.k + 1, m.first}]) {
                    pq.push({newCost, p.k + 1, m.first});
                    best[{p.k + 1, m.first}] = newCost;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    vector<vector<int>> v = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << Solution().findCheapestPrice(3, v, 0, 2, 1);
    return 0;
}
