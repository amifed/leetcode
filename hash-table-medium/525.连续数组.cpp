/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ret = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (mp.find(sum) != mp.end()) {
                ret = max(ret, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (size_t i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << Solution().findMaxLength(v) << endl;
    return 0;
}
