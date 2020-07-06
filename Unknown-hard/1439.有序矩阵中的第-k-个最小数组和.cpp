/*
 * @lc app=leetcode.cn id=1439 lang=cpp
 *
 * [1439] 有序矩阵中的第 k 个最小数组和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // force
    // int kthSmallest(vector<vector<int>> &mat, int k) {
    //     vector<int> ans(mat[0]);
    //     for (int i = 1; i < mat.size(); ++i) {
    //         multiset<int> st;
    //         for (int x : ans) {
    //             for (int y : mat[i]) {
    //                 st.insert(x + y);
    //             }
    //         }
    //         ans.assign(st.begin(), st.end());
    //         ans.resize(min(k, (int)ans.size()));
    //     }
    //     return ans.back();
    // }
    // binary search
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int left = 0, right = 0;
        for (auto row : mat)
            left += row.front(), right += row.back();
        int base = left;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 1;
            dfs(mat, k, mid, 0, base, cnt);
            if (cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
    void dfs(vector<vector<int>> &mat, int &k, int maxSum, int row, int sum, int &cnt) {
        if (row == mat.size() || sum > maxSum || cnt > k)
            return;
        dfs(mat, k, maxSum, row + 1, sum, cnt);
        for (int i = 1; i < mat[row].size(); i++) {
            int tmp = sum + mat[row][i] - mat[row][0];
            if (tmp > maxSum)
                break;
            cnt++;
            dfs(mat, k, maxSum, row + 1, tmp, cnt);
        }
    }
};
// @lc code=end
int main() {
    int m, n, data, k;
    vector<vector<int>> mat;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            cin >> data;
            row.push_back(data);
        }
        mat.push_back(row);
    }
    cin >> k;
    int res = Solution().kthSmallest(mat, k);
    cout << res << endl;
    return 0;
}