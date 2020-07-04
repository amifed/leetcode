/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> st;
        int ret = 0, ptr = 0;
        while (ptr < height.size()) {
            while (!st.empty() && height[ptr] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (!st.empty()) {
                    int di = ptr - st.top() - 1;
                    int hi = min(height[ptr], height[st.top()]) - height[top];
                    ret += di * hi;
                }
            }
            st.push(ptr++);
        }
        return ret;
    }
};
// @lc code=end
int main()

{

    int h;

    vector<int> v;

    while (cin >> h)

    {

        v.push_back(h);
    }

    int res = Solution().trap(v);

    cout << res << endl;

    return 0;
}