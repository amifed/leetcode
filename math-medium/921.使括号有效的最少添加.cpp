/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0, ret = 0;
        for (auto c : S) {
            if (c == '(')
                left++;
            else {
                if (left == 0)
                    ret++;
                else
                    left--;
            }
        }
        return ret + left;
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    cout << Solution().minAddToMakeValid(s) << endl;
    return 0;
}
