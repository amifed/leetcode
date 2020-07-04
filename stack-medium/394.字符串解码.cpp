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
    string vectorToString(vector<string> v) {
        string ret = "";
        for (const auto &s : v)
            ret.append(s);
        return ret;
    }
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
                vector<string> strs;
                while (st.back() != "[") {
                    strs.push_back(st.back());
                    st.pop_back();
                }
                st.pop_back(); //左括号
                reverse(strs.begin(), strs.end());
                int repeat = stoi(st.back());
                st.pop_back();
                string ret, sub = vectorToString(strs);
                while (repeat--)
                    ret.append(sub);
                st.push_back(ret);
                ptr++;
            } else {
                st.push_back(string(1, s[ptr++]));
            }
        }
        return vectorToString(st);
    }
};
// @lc code=end
int main() {
    string str;
    getline(cin, str);
    string result = Solution().decodeString(str);
    cout << result << endl;
    return 0;
}