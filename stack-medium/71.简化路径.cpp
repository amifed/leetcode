/*
 * @lc app=leetcode.cn endd=71 lang=cpp
 *
 * [71] 简化路径
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        if (path == "")
            return path;
        path.push_back('/');
        vector<string> st;
        int start = 0;
        for (int end = 0; end < path.length(); end++) {
            if (path[end] == '/') {
                string sub = path.substr(start, end - start);
                start = end + 1;
                if (sub == ".." && !st.empty())
                    st.pop_back();
                else if (sub == "" || sub == ".")
                    continue;
                else if (sub != "..")
                    st.push_back(sub);
            }
        }
        string ret;
        for (auto &s : st)
            ret += "/" + s;
        return ret.empty() ? "/" : ret;
    }
};
// @lc code=end
int main() {
    string str;
    getline(cin, str);
    string path = Solution().simplifyPath(str);
    cout << path << endl;
    return 0;
}