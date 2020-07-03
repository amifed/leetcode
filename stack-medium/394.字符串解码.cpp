/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        vector<string> st;
        int ptr = 0;
        while (ptr < s.length()) {
            if (isdigit(s[ptr])) {
                string num = "";
                while (ptr < s.length() && isdigit(s[ptr]))
                    num.push_back(s[ptr++]);
                st.push_back(num);
            } else if (s[ptr] == ']') {
                string sub;
                while (st.back() != "[") {
                    sub.append(st.back());
                    st.pop_back();
                }
                st.pop_back(); //左括号
                reverse(sub.begin(), sub.end());
                int repeat = stoi(st.back());
                st.pop_back();
                string ret;
                while (repeat--)
                    ret.append(sub);
                st.push_back(ret);
                ptr++;
            } else {
                st.push_back(string(1, s[ptr++]));
            }
        }
        string ret;
        for (const auto &sub : st)
            ret.append(sub);
        return ret;
    }
};
// @lc code=end
int main() {
    string s = "3[a2[bc]]";
    cout << Solution().decodeString(s);
    return 0;
}