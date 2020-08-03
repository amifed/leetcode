/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int smaller(int m, int n, int num) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(num / i, n);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (smaller(m, n, mid) < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end