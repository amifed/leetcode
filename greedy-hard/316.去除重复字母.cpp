/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_set<char> ins;
        int mapp[26] = {0};
        for (auto c : s)
            mapp[c - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (ins.find(s[i]) == ins.end()) {
                while (!st.empty() && st.top() > s[i] && mapp[st.top() - 'a'] > 0) {
                    ins.erase(st.top());
                    st.pop();
                }
                ins.insert(s[i]);
                st.push(s[i]);
            }
            mapp[s[i] - 'a']--;
        }
        string ret;
        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end
int main() {
    string s;
    cin >> s;
    cout << Solution().removeDuplicateLetters(s);
    return 0;
}