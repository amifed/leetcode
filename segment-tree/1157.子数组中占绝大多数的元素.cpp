/*
 * @lc app=leetcode.cn id=1157 lang=cpp
 *
 * [1157] 子数组中占绝大多数的元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/* class MajorityChecker {
private:
vector<vector<int>> pos;
public:
    MajorityChecker(vector<int>& arr) {
        pos.resize(20001);
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold) {
        for (int i = 1; i <= 20000; i++) {
            if (pos[i].size() < threshold) continue;
            auto u = upper_bound(pos[i].begin(), pos[i].end(), right);
            auto l = lower_bound(pos[i].begin(), pos[i].end(), left);
            if (u - l >= threshold) return i;
        }
        return -1;
    }
}; */
struct Node {
    int val, cnt;
    Node operator+(const Node &other) {
        Node node;
        if (val == other.val) {
            node.val = val;
            node.cnt = cnt + other.cnt;
        } else if (cnt >= other.cnt) {
            node.val = val;
            node.cnt = cnt - other.cnt;
        } else {
            node.val = other.val;
            node.cnt = other.cnt - cnt;
        }
        return node;
    }
};
class MajorityChecker {
private:
    int n;
    vector<int> pos[20001];
    Node d[65536];

public:
    MajorityChecker(vector<int> &arr) {
        n = arr.size();
        for (int i = 0; i < n; i++) {
            pos[arr[i]].push_back(i);
        }
        build(0, n - 1, 1, arr);
    }

    void build(int s, int t, int p, vector<int> &a) {
        if (s == t) {
            d[p] = {a[s], 1};
            return;
        }
        int m = (s + t) >> 1;
        build(s, m, p << 1, a), build(m + 1, t, (p << 1) | 1, a);
        d[p] = d[p << 1] + d[(p << 1) | 1];
    }
    Node getsum(int l, int r, int s, int t, int p) {
        if (l <= s && t <= r) {
            return d[p];
        }
        int m = (s + t) >> 1;
        Node sum = {0, 0};
        if (l <= m) sum = sum + getsum(l, r, s, m, p << 1);
        if (r > m) sum = sum + getsum(l, r, m + 1, t, (p << 1) | 1);
        return sum;
    }
    int query(int left, int right, int threshold) {
        Node node = getsum(left, right, 0, n - 1, 1);
        int val = node.val;
        auto u = upper_bound(pos[val].begin(), pos[val].end(), right);
        auto l = lower_bound(pos[val].begin(), pos[val].end(), left);
        if (u - l >= threshold) return val;
        return -1;
    }
};
/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
// @lc code=end
