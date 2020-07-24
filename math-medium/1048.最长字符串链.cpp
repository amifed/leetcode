/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool check(vector<vector<int>> &counter, int a, int b) {
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += abs(counter[a][i] - counter[b][i]);
        return cnt == 1;
    }
    int longestStrChain(vector<string> &words) {
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.length() < b.length();
        });
        vector<vector<int>> counter(words.size(), vector<int>(26, 0));
        for (int i = 0; i < words.size(); i++)
            for (auto ch : words[i])
                counter[i][ch - 'a']++;
        int ret = 1;
        vector<int> dp(words.size(), 1);
        for (int i = 1; i < words.size(); i++) {
            for (int j = i - 1; j > -1 && words[i].length() - words[j].length() < 2; j--) {
                if (words[i].length() - words[j].length() == 1 && check(counter, i, j)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
// @lc code=end
