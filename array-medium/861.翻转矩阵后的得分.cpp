/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // int matrixScore(vector<vector<int>> &A) {
    //     int m = A.size(), n = A[0].size();
    //     for (int i = 0; i < m; i++) {
    //         if (A[i][0] == 0) {
    //             for (int j = 0; j < n; j++)
    //                 A[i][j] ^= 1;
    //         }
    //     }
    //     int ret = (1 << (n - 1)) * m;
    //     for (int i = 1; i < n; i++) {
    //         int cnt = 0;
    //         for (int j = 0; j < m; j++)
    //             cnt += A[j][i];
    //         ret += (1 << (n - i - 1)) * max(cnt, m - cnt);
    //     }
    //     return ret;
    // }
    int matrixScore(vector<vector<int>> &A) {
        int m = A.size(), n = A[0].size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++)
                cnt += A[j][i] ^ A[j][0];
            ret += max(cnt, m - cnt) * (1 << (n - i - 1));
        }
        return ret;
    }
};
// @lc code=end
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    cout << Solution().matrixScore(v);
    return 0;
}