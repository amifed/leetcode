#include <bits/stdc++.h>
using namespace std;
class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int n) {
        tree.resize(n + 1, 0);
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int pos, int delta = 1) {
        while (pos < tree.size()) {
            tree[pos] += delta;
            pos += lowbit(pos);
        }
    }
    int query(int pos) {
        int sum = 0;
        while (pos > 0) {
            sum += tree[pos];
            pos -= lowbit(pos);
        }
        return sum;
    }
};
// https://www.acwing.com/blog/content/80/