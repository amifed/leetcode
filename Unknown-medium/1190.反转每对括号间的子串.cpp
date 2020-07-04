/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // stack with string::iterator and reverse orginal string
    // string reverseParentheses(string s) {
    //     stack<string::iterator> st;
    //     for (auto it = s.begin(); it != s.end(); it++) {
    //         if (*it == '(')
    //             st.push(it);
    //         else if (*it == ')') {
    //             reverse(st.top(), it);
    //             st.pop();
    //         }
    //     }
    //     string ret;
    //     for (auto c : s) {
    //         if (isalpha(c))
    //             ret.push_back(c);
    //     }
    //     return ret;
    // }
    // stack with temp substring
    string reverseParentheses(string s) {
        string ret;
        stack<string> st;
        for (auto &c : s) {
            if (c == '(') {
                st.push(ret);
                ret.clear();
            } else if (c == ')') {
                reverse(ret.begin(), ret.end());
                ret = st.top() + ret;
                st.pop();
            } else
                ret.push_back(c);
        }
        return ret;
    }
};
// @lc code=end
int main() {
    string s;
    cin >> s;
    cout << Solution().reverseParentheses(s) << endl;
    return 0;
}